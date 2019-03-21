package app;

import java.time.DayOfWeek;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.LocalTime;
import java.time.temporal.ChronoUnit;
import java.time.temporal.TemporalAdjuster;
import java.time.temporal.TemporalAdjusters;

public class Main {

    public static void main(String[] args) {


        /** LocalDate - date in ISO format yyyy-MM-dd without time
         *  can be created by using system clock, 'of' on integers or 'parse' metghd on string
         */
        //get today's local date
        LocalDate localDate = LocalDate.now();
        System.out.println(localDate);

        //read date from ints or string
        LocalDate localDate1 = LocalDate.of(2019,02,27);
        LocalDate localDate2 = LocalDate.parse("2019-04-20");

        //add days/months/years etc. to local date
        LocalDate tomorrow = LocalDate.now().plusDays(1);
        System.out.println(tomorrow);

        //substract a given number of days/months/years/centuries etc. from local date
        LocalDate prevoiusMonthSameDay = LocalDate.now().minus(1, ChronoUnit.MONTHS);
        System.out.println(prevoiusMonthSameDay);

        //get the day of week
        DayOfWeek day = LocalDate.now().getDayOfWeek();
        System.out.println(day);

        //get the number of day in month
        int dayOfMonth = LocalDate.now().getDayOfMonth();
        System.out.println(dayOfMonth);

        //compare two dates
        boolean notBefore = LocalDate.parse("2019-07-14").isBefore(LocalDate.parse("2019-08-13"));
        System.out.println(notBefore);

        boolean isAfter = LocalDate.parse("2018-07-03").isAfter(LocalDate.parse("2015-07-21"));
        System.out.println(isAfter);

        //obtain date boundaries
        LocalDateTime beginningOfDay = LocalDate.parse("2016-07-23").atStartOfDay();
        System.out.println(beginningOfDay);

        LocalDate firstDayOfMonth = LocalDate.parse("2016-09-11").with(TemporalAdjusters.firstDayOfMonth());
        System.out.println(firstDayOfMonth);

        /**LocalTime - time without date
         *
         */

        //three ways of assigning LocalTime value
        LocalTime now = LocalTime.now();
        System.out.println(now);

        LocalTime sixThirty = LocalTime.parse("06:30");
        System.out.println(sixThirty);

        LocalTime sevenThirty = LocalTime.of(7,30);
        System.out.println(sevenThirty);

        //adding hours/seconds etc...
        LocalTime eightThirty = sevenThirty.plus(1,ChronoUnit.HOURS);
        System.out.println(eightThirty);

        //assigning hour/minute etc. value to int
        int six = LocalTime.parse("06:55").getHour();
        System.out.println(six);

        //comparing
        boolean isTimeBefore = LocalTime.parse("08:20").isBefore(LocalTime.of(10,15));
        System.out.println(isTimeBefore);

        //max time value - useful for in databeses for quering record in a given span of time
        LocalTime max = LocalTime.MAX;
        System.out.println(max);



    }
}
