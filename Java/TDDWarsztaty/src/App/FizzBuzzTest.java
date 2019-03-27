package App;

import org.junit.Assert;
import org.junit.Test;

public class FizzBuzzTest {

    FizzBuzz fizzBuzz = new FizzBuzz();

    @Test
    public void should_one_on_input_return_one_on_output(){
        int input = 1;
        String result = fizzBuzz.doFizz(input);
        Assert.assertEquals("1",result);
    }

    @Test
    public void should_two_on_input_return_two_on_output(){
        int input = 2;
        String result = fizzBuzz.doFizz(input);
        Assert.assertEquals("2",result);

    }

    @Test
    public void should_three_on_input_return_FIZZ_on_output(){
        int input = 3;
        String result = fizzBuzz.doFizz(input);
        Assert.assertEquals("FIZZ", result);
    }

    @Test
    public void should_five_on_input_return_BUZZ_on_output(){
        int input = 5;
        String result = fizzBuzz.doFizz(input);
        Assert.assertEquals("BUZZ", result);
    }

    @Test
    public void should_fifteen_on_input_returnFIZZBUZZ_on_output(){
        int input = 15;
        String result = fizzBuzz.doFizz(input);
        Assert.assertEquals("FIZZBUZZ", result);
    }
}
