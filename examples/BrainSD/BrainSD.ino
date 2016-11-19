// Arduino Brain Library - Brain Serial Test

// Description: Grabs brain data from the serial RX pin and sends CSV out over the TX pin (Half duplex.)
// More info: https://github.com/kitschpatrol/Arduino-Brain-Library
// Author: Eric Mika, 2010 revised in 2014

#include <Brain.h>

#include <SPI.h>
#include <SD.h>

const int chipSelect = 25;

// Set up the brain parser, pass it the hardware serial object you want to listen on.
Brain brain(Serial);
int i = 0;
void setup() {
  // Start the hardware serial.
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.print("Initializing SD card...");

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");
}

void loop() {
  // Expect packets about once per second.
  // The .readCSV() function returns a string (well, char*) listing the most recent brain data, in the following format:
  // "signal strength, attention, meditation, delta, theta, low alpha, high alpha, low beta, high beta, low gamma, high gamma"
  
  while (i < 500)
  {
    if (brain.update()&& brain.hasPower) {
  
    //Serial.println(brain.readErrors());
    //Serial.println(brain.readCSV());
    File dataFile = SD.open("brain1.txt", FILE_WRITE);
    if (dataFile) {
      dataFile.println(brain.readCSV());
      dataFile.close();
      // print to the serial port too:
      //    Serial.println(dataString);
    }
    i += 1;
  }
  }
}

