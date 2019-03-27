package snow;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.InjectMocks;
import org.mockito.Mock;
import org.mockito.runners.MockitoJUnitRunner;
import snow.dependencies.MunicipalServices;
import snow.dependencies.PressService;
import snow.dependencies.SnowplowMalfunctioningException;
import snow.dependencies.WeatherForecastService;

import javax.naming.ldap.PagedResultsControl;

import static org.mockito.Mockito.*;

/** Mock
 * ten framework pozwala robic testy na golych obiektach
 * z niezaimplementowanymi metodami.
 */

@RunWith(MockitoJUnitRunner.class)
public class SnowRescueServiceTest {

    //@Mock - program wie, ze bedziemy sami implementowali ponizsze rozwiazania
    @Mock
    WeatherForecastService weatherForecastService;
    @Mock
    PressService pressService;
    @Mock
    MunicipalServices municipalServices;

    @InjectMocks
    SnowRescueService snowRescueService =
            new SnowRescueService(weatherForecastService, municipalServices, pressService);


    @Test
    public void should_send_sander_if_temperature_below_0(){

        //uzycie Mockito - when, verify

        //BDD - given
        //symulujemy zachowanie niezaimplementowanej metody - zwraca -1
        when(weatherForecastService.getAverageTemperatureInCelsius()).thenReturn(-1);

        //BDD - when
        //wywolujemy testowana metode
        snowRescueService.checkForecastAndRescue();

        //BDD -then
        //sprawdzamy, czy poprzednia metoda wywolala 1 raz funkcje sendSander
        verify(municipalServices, times(1)).sendSander();

    }

    @Test
    public void should_send_snowplow_if_snowfall_over_3(){

        //uzycie Mockito - when, verify

        //BDD - given
        when(weatherForecastService.getSnowFallHeightInMM()).thenReturn(4);
        //BDD - when
        snowRescueService.checkForecastAndRescue();

        //BDD -then
        verify(municipalServices, times(1)).sendSnowplow();

    }

    @Test
    public void should_send_second_snowplow_if_first_failed(){

        //uzycie Mockito - when, verify

        //BDD - given
        //wymuszanie rzucenia wyjatki
        //doNothing - zeby sie nie wysypal na wyjatku
        doThrow(SnowplowMalfunctioningException.class).doNothing().when(municipalServices).sendSnowplow();
        when(weatherForecastService.getSnowFallHeightInMM()).thenReturn(4);

        //BDD - when
        snowRescueService.checkForecastAndRescue();

        //BDD -then
        //uwaga - dwa razy wywolujemy metode
        verify(municipalServices, times(2)).sendSnowplow();

    }

    @Test
    public void should_send_two_snowplows_if_snawfall_over_5(){

        //uzycie Mockito - when, verify

        //BDD - given
        when(weatherForecastService.getSnowFallHeightInMM()).thenReturn(6);

        //BDD - when
        snowRescueService.checkForecastAndRescue();

        //BDD -then
        //uwaga - dwa razy wywolujemy metode
        verify(municipalServices, times(2)).sendSnowplow();

    }

    @Test
    public void test(){

        //uzycie Mockito - when, verify

        //BDD - given
        when(weatherForecastService.getSnowFallHeightInMM()).thenReturn(12);
        when(weatherForecastService.getAverageTemperatureInCelsius()).thenReturn(-11);

        //BDD - when
        snowRescueService.checkForecastAndRescue();

        //BDD -then
        //uwaga - dwa razy wywolujemy metode
        verify(municipalServices, times(3)).sendSnowplow();
        verify(municipalServices, times(1)).sendSander();
        verify(pressService, times(1)).sendWeatherAlert();

    }

}
