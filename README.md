ESP8266Time Edited by 3tawi
ESP8266Time Library: https://github.com/3tawi/Esp8266Time
Find All "Great Projects" Videos : https://www.youtube.com/c/GreatProjects

An Arduino library for setting and retrieving internal RTC time on ESP8266 boards

  rtc.setTime(30, 58, 19, 1, 1, 2022);  // 1th Jan 2022 19:58:30
  rtc.setTime(1610897079);  // 1st Jan 2022 00:00:00

getTime("%A, %B %d %Y %H:%M:%S")   // (String) returns time with specified format 
[`Formatting options`](http://www.cplusplus.com/reference/ctime/strftime/)
