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
  else {
    Serial.print("Error opening the file: ");
    Serial.println(fileName);
  }
}

void MicroSD::saveText(String fileName, String content) {
  File microSD_file = SD.open(fileName, FILE_WRITE);

  if (SD.exists(fileName)) {
    Serial.print(fileName);
    Serial.println (" exists");
  }
  else {
    Serial.print(fileName);
    Serial.println(" doesn't exists, CREATING");
  }

  if (microSD_file) {
    Serial.print("Writing in: ");
    Serial.println(fileName);
    microSD_file.println(content);
    microSD_file.close();
  }
  else {
    Serial.print("Error opening the file: ");
    Serial.println(fileName);
  }
}