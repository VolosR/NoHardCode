#include <LilyGo_AMOLED.h>
#include "bigFont.h"
#include "midleFont.h"
#include "smallFont.h"
#include "valueFont.h"
#include "secFont.h"
#include <WiFiManager.h>
#include <TFT_eSPI.h>
#include <ArduinoJson.h>
#include <HTTPClient.h>
#include <ESP32Time.h>
TFT_eSPI tft = TFT_eSPI();
TFT_eSprite sprite = TFT_eSprite(&tft);
LilyGo_Class amoled;
double rad=0.01745;

float x[360]; //outer point
float y[360];
float px[360]; //ineer point
float py[360];
float lx[360]; //long line 
float ly[360];
float shx[360]; //short line 
float shy[360];
float tx[360]; //text
float ty[360];

int PPgraph[34]={0};

int angle=0;
int value=0;
int chosenFont;
int chosenColor;
int r=118;
int sx=0;
int sy=120;
int inc=18;
int a=0;
int prev=0;
String secs="00";
int second1=0;
int second2=0;
bool onOff=0;
String OO[2]={"OFF","ON"};
int deb=0;


int n=0;
int xt = 0, yt = 0;

unsigned short grays[13];
#define red 0xD041
#define blue 0x0AD0
#define yellow 0x9381
#define bck TFT_BLACK
char dd[7]={'s','m','t','w','t','f','s'};
String months[12] = {
  "January", "February", "March", "April", "May", "June", 
  "July", "August", "September", "October", "November", "December"
};

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


  rtc.setTime(0,47,23,10,23,2023,0); 
  Serial.begin();
  amoled.begin();
  amoled.setBrightness(120);
  sprite.createSprite(536,240);

     int co=220;
     for(int i=0;i<13;i++)
     {
     grays[i]=tft.color565(co, co, co);
     co=co-20;
     }

       for(int i=0;i<360;i++)
  {
       x[i]=(r*cos(rad*i))+sx;
       y[i]=(r*sin(rad*i))+sy;
       px[i]=((r-5)*cos(rad*i))+sx;
       py[i]=((r-5)*sin(rad*i))+sy;

       lx[i]=((r-24)*cos(rad*i))+sx;
       ly[i]=((r-24)*sin(rad*i))+sy;

       shx[i]=((r-12)*cos(rad*i))+sx;
       shy[i]=((r-12)*sin(rad*i))+sy;

      tx[i]=((r+28)*cos(rad*i))+sx;
      ty[i]=((r+28)*sin(rad*i))+sy;
  }

     WiFiManager wifiManager;
    wifiManager.setConfigPortalTimeout(5000);

    if(!wifiManager.autoConnect("VolosWifiConf","password")) {
        Serial.println("Failed to connect and hit timeout");
        delay(3000);
        ESP.restart();
    }
    Serial.println("Connected.");
  
  getTime();
  draw();
}

void draw()
{
 
  sprite.fillSprite(grays[11]);

  sprite.fillSmoothCircle(536,240,300,0x0147,grays[11]);
  sprite.fillSmoothCircle(536,260,280,grays[11],0x0147);

    sprite.fillSmoothCircle(580,240,270,0x0147,grays[11]);
  sprite.fillSmoothCircle(580,260,255,grays[11],0x0147);

  sprite.drawWedgeLine(58,120,80,120,3,2,TFT_RED);
    for(int j=0;j<33;j++)
    for(int i=0;i<PPgraph[j];i++)
    sprite.fillRect(208+(j*6),85-(i*4),4,3,grays[5]);
  
 sprite.fillRect(200,136,130,3,grays[7]);
 sprite.fillRect(208,130,3,40,grays[7]);


  sprite.setTextDatum(4);
  sprite.loadFont(smallFont);
  sprite.drawString("%",60,108);
  sprite.drawString("THANK YOU",476,100);
  sprite.unloadFont();

   sprite.loadFont(midleFont);

   for(int i=0;i<120;i++)
 {
   a=angle+(i*3);
   if(a>359)
   a=(angle+(i*3))-360;
   

   sprite.fillCircle(x[a],y[a],1,grays[6]);
   sprite.setTextColor(grays[2],grays[8]);

   if(i%3==0)
   sprite.drawWedgeLine(x[a],y[a],x[a]-6,y[a],1,1,grays[5],bck);

   if(i%6==0)
   sprite.drawWedgeLine(x[a],y[a],x[a]-18,y[a],2,2,grays[4],bck);
   if(i%12==0){
   sprite.drawWedgeLine(x[a],y[a],x[a]-30,y[a],2,2,grays[3],bck);
   sprite.drawString(String((i/6)*5),tx[a],ty[a],2);
   }

}
    


  sprite.setTextDatum(4);
  sprite.setTextColor(grays[2],grays[8]);
  
  for(int i=0;i<7;i++)
  {
    sprite.fillSmoothRoundRect(206+(i*30),2,26,26,3,grays[8],bck);
    sprite.drawString(String(dd[i]),206+((i+1)*30)-17,17);
  }
  sprite.unloadFont();
  sprite.drawWedgeLine(219+(rtc.getDayofWeek()*30),35,219+(rtc.getDayofWeek()*30),40,1,3,grays[3],bck);
  
  
  sprite.setTextDatum(0);
  sprite.setTextColor(grays[0],bck);
  sprite.loadFont(bigFont);
  sprite.drawString(rtc.getTime().substring(0,5),216,154);
  sprite.unloadFont();

   sprite.setTextDatum(0);
  sprite.setTextColor(grays[1],bck);
  sprite.loadFont(midleFont);
  sprite.drawString(months[rtc.getMonth()]+" "+String(rtc.getDay()),216,100);  ////////////////////////date hard coded
  sprite.setTextDatum(4);
  sprite.fillRect(0,145,50,30,grays[9]);
  sprite.setTextColor(grays[3],grays[9]);
  sprite.drawString(OO[onOff],25,162);  
  sprite.unloadFont();


  sprite.setTextDatum(4);
  sprite.setTextColor(grays[1],bck);
  sprite.loadFont(valueFont);
  sprite.drawString(String((int)(value/10.00)),24,124);
  sprite.setTextColor(grays[7],bck);
  sprite.loadFont(secFont);
  sprite.drawString(secs,474,158);   /// /////////////////////////////////seconds
  sprite.unloadFont();

  sprite.setTextColor(grays[8],bck);
  sprite.drawString("VOLOS PROJECTS",480,236);
  sprite.setTextColor(grays[7],bck);
  amoled.pushColors(0, 0, 536, 240, (uint16_t *)sprite.getPointer());

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

 second1=rtc.getSecond();

 if(second1<10) secs="0"+String(second1); else secs=String(second1);

 if(second1!=second2)
 {second2=second1;
 for(int i=0;i<34;i++)
 PPgraph[i]=random(1,10);}

   angle=angle+1;
   if(angle==360) angle=0;

  value=map(angle,0,359,1000,0);
  if(angle!=prev){
  prev=angle;
  } 
 draw();

    if(millis()>timePassed+1000000)
  {
    getTime();
    timePassed=millis();
  }
}
