#ifndef MICROSD_H
#define MICROSD

#include <SD.h>
#include <SPI.h>

class MicroSD {
  private:
    int pin;

  public:
    MicroSD(int pinMicro) {
      pin = pinMicro;
    }

    void init();
};

#endif