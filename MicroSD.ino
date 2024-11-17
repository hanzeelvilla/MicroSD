#include "MicroSD.h"

MicroSD MSD;

void setup() {
  Serial.begin(115200);
  MSD.init();
}

void loop() {
  MSD.readFile("/example.txt");
  Serial.println("");
  delay(1000);
}
