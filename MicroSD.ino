#include "MicroSD.h"

MicroSD MSD(5);

void setup() {
  Serial.begin(115200);
  MSD.init();
}

void loop() {
  
}
