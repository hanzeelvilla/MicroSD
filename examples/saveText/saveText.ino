#include "MicroSD.h"

MicroSD MSD;

void setup() {
  Serial.begin(115200);
  MSD.init();
}

void loop() {
  MSD.saveText("/hanzeelVilla.txt", "Is very handsome");
  MSD.readFile("/hanzeelVilla.txt");
  delay(1000);
}
