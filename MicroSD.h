#ifndef MICROSD_H
#define MICROSD_H

#include <SD.h>
#include <SPI.h>
#include <ArduinoJson.h>

class MicroSD {
  private:
    int pin;

  public:
    MicroSD(int pinMicro = 5) {
      pin = pinMicro;
    }

    void init();
    void readFile(String fileName);
    void saveText(String fileName, String content);
    void saveJson(String fileName, const JsonDocument& doc);
};

#endif