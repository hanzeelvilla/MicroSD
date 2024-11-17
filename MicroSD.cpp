#include "MicroSD.h"

void MicroSD::init() {
  while (!SD.begin(pin)) {
    Serial.println("Error initializing MicroSD");
  }
  Serial.println("MicroSD initialized");
}


void MicroSD::readFile(String fileName) {
  File microSD_file = SD.open(fileName);

  if (microSD_file) {
    Serial.print("Content: ");

    while (microSD_file.available()) {
      Serial.write(microSD_file.read());
    }

    microSD_file.close();
  }
  else
    Serial.println("Error opening the file");
}