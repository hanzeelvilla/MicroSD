#include "MicroSD.h"
#include "DS1307_RTC.h"
#include <LiquidCrystal_I2C.h>

// this examples needs this library https://github.com/hanzeelvilla/RTC

MicroSD MSD;
DS1307_RTC rtc;
LiquidCrystal_I2C lcd (0x27, 16, 2);

StaticJsonDocument<200> doc;

void setup() {
  Serial.begin(115200);

  rtc.init();
  lcd.init();
  MSD.init();
  lcd.backlight();
}

void loop() {
  String textDate = rtc.formated_date();
  lcd.setCursor(0, 0);
  lcd.print(textDate);
  Serial.println(textDate);

  String textTime = rtc.formated_time();
  lcd.setCursor(0, 1);
  lcd.print(textTime);
  Serial.println(textTime);
  
  String fullTime = rtc.formated_fullDate('_', '_', '_');
  Serial.println(fullTime);

  doc["date"] = textDate;
  doc["time"] = textTime;

  String fileName = "/" + fullTime + ".json";
  Serial.println(fileName);

  MSD.saveJson(fileName, doc);
  
  delay(10000);
}
