//  ESP8266Time Edited by 3tawi
// - ESP8266Time Library: https://github.com/3tawi/Esp8266Time
// Find All "Great Projects" Videos : https://www.youtube.com/c/GreatProjects

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266Time.h>

ESP8266Time rtc;
ESP8266WebServer server(80);

char ssid[] = "Hod-Hod";
char pass[] = "hamza@Hi";
const char* Apssid = "NeoPixel";
const char* Appassword = "3tawi-GP";
  IPAddress ip(192,168,1,143);
  IPAddress dns(192, 168,1,1);
  IPAddress gateway(192, 168,1,1);
  IPAddress gatewayap(192,168,4,1);
  IPAddress subnet(255, 255, 255, 0);
  
void getWifi() {
  WiFi.config(ip, dns, gateway, subnet); 
  WiFi.begin(ssid, pass);
  int xc = 0;
  while (WiFi.status() != WL_CONNECTED && xc < 10) {
    delay(500);
    xc++;
  }
  if (WiFi.status() == WL_CONNECTED) { 
    Serial.print("CONNECTED To: ");
    Serial.println(ssid);
    Serial.print("IP Address: http://");
    Serial.println(WiFi.localIP().toString().c_str());
    WiFi.softAPdisconnect(true);
    } else { 
    WiFi.softAP(Apssid, Appassword);
    Serial.println("CONNECTED To: NeoPixel");
    Serial.println("Password: '3tawi-GP'");
    Serial.print("IP Address: http://");
    Serial.println(WiFi.softAPIP().toString().c_str());
    }
}
void setup() {
  Serial.begin(115200);
  rtc.setTime(30, 58, 19, 1, 1, 2022);  // 1th Jan 2022 19:58:30
  //rtc.setTime(1610897079);  // 1st Jan 2022 00:00:00
  getWifi(); 
  configTime(3600, 0, "time.nist.gov", "pool.ntp.org");
  Serial.print("Time Update");
}
void loop() {

  Serial.println(rtc.getTime("%A, %B %d %Y %H:%M:%S"));   // (String) returns time with specified format 
  // formating options  http://www.cplusplus.com/reference/ctime/strftime/
  
  delay(1000);
}
