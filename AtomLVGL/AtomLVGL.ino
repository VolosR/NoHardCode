#include "M5AtomS3.h"
#include <WiFiManager.h>
#include <ArduinoJson.h>
#include <HTTPClient.h>
#include <ESP32Time.h>
#include <lvgl.h>
#include <SPI.h>
#include <Wire.h>
#include "ui.h"

// init the tft espi
static lv_disp_draw_buf_t draw_buf;
static lv_disp_drv_t disp_drv;  // Descriptor of a display driver
static lv_indev_drv_t indev_drv; // Descriptor of a touch driver

#define LV_HOR_RES_MAX 128
#define LV_VER_RES_MAX 128
M5GFX *tft;

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


void tft_lv_initialization() {
  auto cfg = M5.config();
  AtomS3.begin(cfg);
  AtomS3.Display.setBrightness(9);
  lv_init();
  static lv_color_t buf1[(LV_HOR_RES_MAX * LV_VER_RES_MAX) / 10];  // Declare a buffer for 1/10 screen siz
  static lv_color_t buf2[(LV_HOR_RES_MAX * LV_VER_RES_MAX) / 10];  // second buffer is optionnal
  lv_disp_draw_buf_init(&draw_buf, buf1, buf2, (LV_HOR_RES_MAX * LV_VER_RES_MAX) / 10);
  tft=&AtomS3.Lcd;
 
}

void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p) {
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);
  tft->startWrite();
  tft->setAddrWindow(area->x1, area->y1, w, h);
  tft->pushColors((uint16_t *)&color_p->full, w * h, true);
  tft->endWrite();
  lv_disp_flush_ready(disp);
}

void init_disp_driver() {
  lv_disp_drv_init(&disp_drv);  // Basic initialization
  disp_drv.flush_cb = my_disp_flush;  // Set your driver function
  disp_drv.draw_buf = &draw_buf;      // Assign the buffer to the display
  disp_drv.hor_res = LV_HOR_RES_MAX;  // Set the horizontal resolution of the display
  disp_drv.ver_res = LV_VER_RES_MAX;  // Set the vertical resolution of the display
  lv_disp_drv_register(&disp_drv);                   // Finally register the driver
  lv_disp_set_bg_color(NULL, lv_color_hex3(0x000));  // Set default background color to black
}

void setup()
{
   Serial.begin();
      //connect board to wifi
    WiFiManager wifiManager;
    wifiManager.setConfigPortalTimeout(5000);

    if(!wifiManager.autoConnect("VolosWifiConf","password")) {
        Serial.println("Failed to connect and hit timeout");
        delay(3000);
        ESP.restart();
    }
    Serial.println("Connected.");
    getTime();

  tft_lv_initialization();
  init_disp_driver();
  ui_init();
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

void loop()
{
  AtomS3.update();
  lv_task_handler();

      String dateD=String(rtc.getMonth()+1)+"-"+String(rtc.getDay());
      _ui_label_set_property(ui_timeLbl, _UI_LABEL_PROPERTY_TEXT, rtc.getTime().substring(0,5).c_str());
      _ui_label_set_property(ui_secLbl, _UI_LABEL_PROPERTY_TEXT, rtc.getTime().substring(6,8).c_str());
      _ui_label_set_property(ui_dateLbl, _UI_LABEL_PROPERTY_TEXT, dateD.c_str());
      _ui_label_set_property(ui_wdayLbl, _UI_LABEL_PROPERTY_TEXT, rtc.getDate().substring(0,3).c_str());

  if(millis()>timePassed+1000000)
  {
    getTime();
    timePassed=millis();
  }
   
}

