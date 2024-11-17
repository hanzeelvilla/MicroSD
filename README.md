# MicroSD Library

This library provides a simple and intuitive interface for working with MicroSD cards using Arduino. It supports basic file operations like reading, writing text, and saving JSON data.

## Features

* **Initialize MicroSD**: Sets up communication with the MicroSD card.
* **Read File**: Reads the contents of a file and prints it to the Serial Monitor.
* **Save Text**: Saves plain text content to a file on the MicroSD card.
* **Save JSON**: Serializes and writes a JSON object to a file using the ArduinoJson library.

## Requirements

* SD for MicroSD card management.
* SPI for SPI communication.
* ArduinoJson for JSON serialization and deserialization.

## Installation

1. Clone or download this repository as a ZIP file.
2. Place the MicroSD folder into your Arduino libraries directory (typically Documents/Arduino/libraries on most systems).
3. Install the required libraries via the Arduino Library Manager:

## Get started

### Hardware Setup for esp32

* VCC -> 5V
* GND -> GND
* MISO -> 19
* MOSI -> 23
* SCK -> 18
* CS -> 5

### Include the Library in Your Code

In your Arduino code, include the MicroSD.h file and create an instance of the MicroSD.h class.
```
#include "MicroSD.h""
MicroSD MSD;
```

### Initialize the MicroSD with init()

```
MSD.init();
```

### Save a Text

```
MSD.saveText("/your_text_file.txt", "content");
MSD.readFile("/your_text_file.txt");
```

### Save a JSON

```
StaticJsonDocument<200> doc;

void setup() {
  MSD.init();

  doc["name"] = "name";
  doc["lastName"] = "lastName";
  doc["age"] = 0;
}

void loop() {
  MSD.saveJson("/your_json_file.json", doc);
  MSD.readFile("/your_json_file.json");
}
```

## Notes
* Ensure your MicroSD card is properly formatted *(FAT16 or FAT32).*
* Use the correct *pin number for the CS* (Chip Select) pin in the MicroSD constructor.
* The SD.h library is specific to the Arduino platform and compatible with most MicroSD breakout boards.