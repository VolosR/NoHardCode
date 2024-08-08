#include <WiFiManager.h>
#include <TFT_eSPI.h>
#include <ArduinoJson.h>
#include <HTTPClient.h>
#include <ESP32Time.h>

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite sprite = TFT_eSprite(&tft);

String timeServer = "https://worldtimeapi.org/api/ip";
ESP32Time rtc(0); 

unsigned long timePassed=0; // here we will store time passed

struct DateTime {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  int second;
  long microsecond;
  int offsetHours;
  int offsetMinutes;
};


//convert this format 2024-08-07T20:43:55.697892+02:00  to varables 
DateTime parseISO8601(const String& iso8601) {
  DateTime dt;
  sscanf(iso8601.c_str(), "%4d-%2d-%2dT%2d:%2d:%2d.%6ld%3d:%2d",
         &dt.year, &dt.month, &dt.day,
         &dt.hour, &dt.minute, &dt.second, &dt.microsecond,
         &dt.offsetHours, &dt.offsetMinutes);
  return dt;
}

void setup() {
  Serial.begin();

  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  sprite.createSprite(320,170);
  analogWrite(38,80);  //set brightness

   //connect board to wifi , if cant, esp32 will make wifi network, connect to that network with password "password"
    WiFiManager wifiManager;
    wifiManager.setConfigPortalTimeout(5000);

    if(!wifiManager.autoConnect("VolosWifiConf","password")) {
        Serial.println("Failed to connect and hit timeout");
        delay(3000);
        ESP.restart();
    }
    Serial.println("Connected.");
  
  getTime();
}


void draw()
  {
    sprite.fillSprite(TFT_BLACK); 
    sprite.drawString(rtc.getTime(),60,60,7);
    sprite.pushSprite(0,0);
  }


void getTime()
{
    HTTPClient http;
    String payload; 
   
    http.begin(timeServer);
    int httpResponseCode = http.GET();

    if (httpResponseCode > 0) {
      payload = http.getString();
      Serial.println(httpResponseCode);
      Serial.println(payload);
    } else {
      Serial.print("Error on HTTP1 request: ");
      Serial.println(httpResponseCode);
    }
    http.end();

      StaticJsonDocument<1024> doc;
      DeserializationError error = deserializeJson(doc, payload);
      if (!error) {
      const char* datetime = doc["datetime"];
      DateTime dt = parseISO8601(String(datetime));  

  Serial.print("Year: "); Serial.println(dt.year);
  Serial.print("Month: "); Serial.println(dt.month);
  Serial.print("Day: "); Serial.println(dt.day);
  Serial.print("Hour: "); Serial.println(dt.hour);
  Serial.print("Minute: "); Serial.println(dt.minute);
  Serial.print("Second: "); Serial.println(dt.second);

  rtc.setTime(dt.second, dt.minute, dt.hour, dt.day, dt.month, dt.year); 
  }
}

void loop() {
  draw();
    if(millis()>timePassed+1000000)
  {
    getTime();
    timePassed=millis();
  }
}
