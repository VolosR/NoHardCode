#include "M5AtomS3.h"
#include "smallFont.h"
#include "middleFont.h"
#include <WiFiManager.h>
#include <TFT_eSPI.h>
#include <ArduinoJson.h>
#include <HTTPClient.h>
#include <ESP32Time.h>

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite spr = TFT_eSprite(&tft);
TFT_eSprite mainSpr = TFT_eSprite(&tft);

unsigned short grays[15];
unsigned short blue=0x01EC;
unsigned short light=0x7E3E; 

int valueX=0;
int valueY=0;
int angle=0;
int angle2=0;
int t=0;

String timeServer = "https://worldtimeapi.org/api/ip";
ESP32Time rtc(0); 

unsigned long timePassed=0;

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

DateTime parseISO8601(const String& iso8601) {
  DateTime dt;
  sscanf(iso8601.c_str(), "%4d-%2d-%2dT%2d:%2d:%2d.%6ld%3d:%2d",
         &dt.year, &dt.month, &dt.day,
         &dt.hour, &dt.minute, &dt.second, &dt.microsecond,
         &dt.offsetHours, &dt.offsetMinutes);
  return dt;
}



void setup() {
    auto cfg = M5.config();
    AtomS3.begin(cfg);
    AtomS3.Display.setBrightness(30);
    spr.createSprite(128, 128);
    mainSpr.createSprite(128, 128);
    
    //connect board to wifi
    WiFiManager wifiManager;
    wifiManager.setConfigPortalTimeout(5000);

    if(!wifiManager.autoConnect("VolosWifiConf","password")) {
        Serial.println("Failed to connect and hit timeout");
        delay(3000);
        ESP.restart();
    }
    Serial.println("Connected.");

    int co = 225;
    for (int i = 0; i < 15; i++) {
    grays[i] = tft.color565(co, co, co);
    co = co - 15;
  }
  getTime();
}

void draw()
{

spr.fillSprite(TFT_BLACK);

for(int i=1;i<15;i++)
spr.drawSmoothArc(64,64,55,44,i*12-3,(i*12-3)+6,blue,TFT_BLACK);

for(int i=0;i<16;i++)
spr.drawSmoothArc(64,64,49,45,194+(i*10),194+(i*10)+4,TFT_ORANGE,TFT_BLACK);

spr.drawSmoothArc(64,64,62,38,86,94,light,TFT_BLACK);
spr.drawSmoothArc(64,64,62,38,176,184,light,TFT_BLACK);
spr.drawSmoothArc(64,64,62,38,0,4,light,TFT_BLACK);
spr.drawSmoothArc(64,64,62,38,356,360,light,TFT_BLACK);
spr.drawSmoothArc(64,64,39,38,194,346,TFT_MAGENTA,TFT_BLACK);

mainSpr.fillSprite(TFT_BLACK);
spr.pushRotated(&mainSpr,angle);

mainSpr.fillCircle(64,64,2,grays[7]);
mainSpr.drawFastHLine(38,64,26,grays[9]);
mainSpr.drawFastVLine(64,52,28,grays[9]);

mainSpr.setTextDatum(4);
mainSpr.setTextColor(grays[0],TFT_BLACK);
mainSpr.loadFont(middleFont);
mainSpr.drawString(rtc.getTime().substring(0,2),46,52);
mainSpr.drawString(rtc.getTime().substring(3,5),82,70);
mainSpr.unloadFont();

mainSpr.loadFont(smallFont);
mainSpr.setTextColor(grays[11],TFT_BLACK);
mainSpr.drawString(rtc.getTime().substring(6,8),50,82);
mainSpr.unloadFont();
mainSpr.drawString("MIN",80,48);
mainSpr.drawString(String(angle2),100,14);

for(int i=0;i<20;i++)
if(i==angle2)
mainSpr.fillRect(124,4+(i*6),4,4,TFT_WHITE);
else
mainSpr.fillRect(124,4+(i*6),4,4,grays[12]);


AtomS3.Display.pushImage(0, 0, 128, 128, (uint16_t*)mainSpr.getPointer());
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
  Serial.print("Microsecond: "); Serial.println(dt.microsecond);
  Serial.print("Offset Hours: "); Serial.println(dt.offsetHours);
  Serial.print("Offset Minutes: "); Serial.println(dt.offsetMinutes);

  rtc.setTime(dt.second, dt.minute, dt.hour, dt.day, dt.month, dt.year); 
  }
}

void loop() {
    auto imu_update = M5.Imu.update();
    if (imu_update) {
      
        auto data = M5.Imu.getImuData();
        valueX=data.accel.x*100;  
        angle2=data.accel.z*100;  
        angle2=map(angle2,-100,100,0,20);  
      
        if(valueX>=0)
        angle=map(valueX,1,100,1,90);

        if(valueX<0)
        angle=map(valueX,-1,-100,-1,-90);
        }       

draw();

  if(millis()>timePassed+1000000)
  {
    getTime();
    timePassed=millis();
  }

}
