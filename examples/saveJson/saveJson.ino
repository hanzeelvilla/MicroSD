#include "MicroSD.h"

MicroSD MSD;
StaticJsonDocument<200> doc;

void setup() {
  Serial.begin(115200);
  MSD.init();

  doc["name"] = "Hanzeel";
  doc["lastName"] = "Villa";
  doc["age"] = 20;
}

void loop() {
  MSD.saveJson("/hanzeelVilla.json", doc);
  MSD.readFile("/hanzeelVilla.json");
  delay(1000);
}
