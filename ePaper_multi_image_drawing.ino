/*

  Hardware Connections:
  BUSY   9
  RST    8
  MISO  12
  MOSI  11
  SCK   13
  SDCS   7
  SRCS   6
  DCS    5
  D/C    4
  GND    GND
  VCC    Logic Level (if using 5V logic (e.g. Arduino) connect to 5V. if using 3.3V logic (e.g. Teensy) connect to 3.3V)

*/

//Click here to get the library: http://librarymanager/All#SparkFun_ePaper
#include "SparkFun_ePaper_154.h"
//#include "SparkFun_ePaper_420.h"
//#include "SparkFun_ePaper_750.h"

//You must also have the SparkFun HyperDisplay library
//Click here to get the library: http://librarymanager/All#SparkFun_HyperDisplay
#include "hyperdisplay.h"

#include <SPI.h>
#include <SD.h>

const byte busyPin = 9;
const byte resetPin = 8;
const byte sdCSPin = 7;
const byte srCSPin = 6;
const byte dCSPin = 5;
const byte dcPin = 4;

//Uncomment your display size
EPAPER_154 myEPaper;
//EPAPER_420 myEPaper;
//EPAPER_750 myEPaper;


void setup() {

  Serial.begin(9600);

  if (myEPaper.begin(busyPin, resetPin, sdCSPin, srCSPin, dCSPin, dcPin) == false)
    Serial.println("No SD Card Detected");

}

void loop() {

    int array[] = {"img1.bmp", "img2.bmp", "img3.bmp", "img4.bmp", "img5.bmp", "img6.bmp", "img7.bmp", "img8.bmp", "img9.bmp", "img10.bmp", "img11.bmp", "img12.bmp"};

    Serial.println("There's ");
    Serial.println(sizeof(array)/sizeof(array[0]));
    Serial.println(" images in the array");

  for (int i = 0; i < sizeof(array)/sizeof(array[0]) - 1; i++) {

    //load bitmap named "img.bmp" from SD card with white threshold at 120 and red threshold at 100
    //threshold range 0-255, lower values for white will produce an output with more white
    //likewise with red

    myEPaper.powerOn();

    Serial.println("Loading BMP");
    if (!myEPaper.bmpFromSD(array[i], 120, 100)) {
      Serial.println("Could not load BMP");
    }
    else {
      Serial.println("Loaded");
    }

    //power off the display when done refreshing to prevent damage
    //follow with powerOn to refresh display again

    myEPaper.powerOff();

  };

}
