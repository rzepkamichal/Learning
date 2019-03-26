package app;

import java.time.*;
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


        /**LocalDateTime
         * - combination of LocalDate and LocalTame
         */

        //some ways to obtain an instance

        LocalDateTime dateTime = LocalDateTime.now();
        LocalDateTime dateTime1 = LocalDateTime.of(2019, Month.AUGUST, 20, 04, 30);
        LocalDateTime dateTime2 = LocalDateTime.parse("2019-03-21T08:29:00");

        System.out.println(dateTime);
        System.out.println(dateTime1);
        System.out.println(dateTime2);

        //plus and minus methods

        LocalDateTime dateTime3 = dateTime.plusDays(21);
        LocalDateTime dateTime4 = dateTime1.minusHours(5);

        System.out.println();
        System.out.println(dateTime3);
        System.out.println(dateTime4);

        System.out.println();

        //dealing with time zone specific date and time - three ways of obtaining zoned time

        //using zoneId
        ZoneId zoneId = ZoneId.of("Europe/Paris");
        ZonedDateTime zonedDateTime = ZonedDateTime.of(dateTime, zoneId);

        //by parsing
        ZonedDateTime zonedDateTime1 = ZonedDateTime.parse("2019-08-25T10:15:30+01:00[Europe/Paris]");

        System.out.println(zonedDateTime);
        System.out.println(zonedDateTime1);
        System.out.println();

        //zone offset
        LocalDateTime localDateTime = LocalDateTime.of(2019, Month.APRIL, 12, 5, 30);

        ZoneOffset offset = ZoneOffset.of("+02:00");
        OffsetDateTime offsetDateTime = OffsetDateTime.of(localDateTime, offset);

        System.out.println(offsetDateTime);

        /** Period and Duration
         *
         */

        //Period - difference between to dates
        System.out.println();
        LocalDate initialDate = LocalDate.parse("2017-03-15");
        LocalDate finalDate = initialDate.plusDays(10);

        int period = Period.between (initialDate, finalDate).getDays();
        long period1 = ChronoUnit.DAYS.between(initialDate, finalDate);

        System.out.println(period);
        System.out.println(period1);

        System.out.println();

        //Duration - dealing with time

        LocalTime initialTime = LocalTime.of(8,20,31);
        LocalTime finalTime = LocalTime.of(16,54,43);

        long duration = Duration.between(initialTime,finalTime).getSeconds();
        long duration1 = ChronoUnit.SECONDS.between(initialTime, finalTime);

        System.out.println(duration);
        System.out.println(duration1);
        System.out.println();

        /**Compatibility with Date and Calendar
         *
         */






    }
}
