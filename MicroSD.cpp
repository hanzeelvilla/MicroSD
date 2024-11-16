#include "MicroSD.h"

void MicroSD::init() {
  while (!SD.begin(pin)) {
    Serial.println("Error initializing MicroSD");
  }
  Serial.println("MicroSD initialized");
}