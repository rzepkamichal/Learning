package snow;

import org.mockito.InjectMocks;
import org.mockito.Mock;
import snow.dependencies.MunicipalServices;
import snow.dependencies.PressService;
import snow.dependencies.SnowplowMalfunctioningException;
import snow.dependencies.WeatherForecastService;

public class SnowRescueService {


	WeatherForecastService weatherForecastService;
	PressService pressService;
	MunicipalServices municipalServices;


	public SnowRescueService(WeatherForecastService weatherForecastService, MunicipalServices municipalServices, PressService pressService) {
		this.weatherForecastService = weatherForecastService;
		this.pressService = pressService;
		this.municipalServices = municipalServices;
	}

	public void checkForecastAndRescue() {

		if(weatherForecastService.getAverageTemperatureInCelsius() < -10 && weatherForecastService.getSnowFallHeightInMM() > 10){
			municipalServices.sendSnowplow();
			municipalServices.sendSnowplow();
			municipalServices.sendSnowplow();
			municipalServices.sendSander();
			pressService.sendWeatherAlert();
			return;
		}


		if(weatherForecastService.getAverageTemperatureInCelsius() < 0){
			municipalServices.sendSander();
			return;
		}

		if(weatherForecastService.getSnowFallHeightInMM() > 5){
			municipalServices.sendSnowplow();
			municipalServices.sendSnowplow();
			return;
		}


		if(weatherForecastService.getSnowFallHeightInMM() > 3){
			try {
				municipalServices.sendSnowplow();
			}catch(SnowplowMalfunctioningException e){
				municipalServices.sendSnowplow();
			}
		}






	}
}


