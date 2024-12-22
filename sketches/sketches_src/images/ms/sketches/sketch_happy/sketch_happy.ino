/* Sketch for Animals emotive display  */
#include <SPI.h>
#include <SD.h>
#include <TFT.h>  // Arduino LCD library
// pin definition for the Uno
#define sd_cs  4
#define lcd_cs 10
#define dc     9
#define rst    8
// the screen object
TFT TFTscreen = TFT(lcd_cs, dc, rst);
// the image to be drawn on screen
PImage emotive;
// runs when the program starts
void setup() {
  // initialize the GLCD
  TFTscreen.begin();
  TFTscreen.background(255, 255, 255);
  TFTscreen.stroke(0, 0, 255);
  TFTscreen.stroke(0, 0, 0);
  // initialize the serial port
  Serial.begin(9600);
  //while (!Serial) {
    // wait for serial port to connect
  //}
  // clear the GLCD screen before starting
  TFTscreen.background(255, 255, 255);
  // try to access the SD card
  if (!SD.begin(sd_cs)) {
    Serial.println(F("failed!"));
    return;
  }
  // initialize and clear the GLCD screen
  TFTscreen.begin();
  TFTscreen.background(255, 255, 255);
  // try to load the image
  emotive = TFTscreen.loadImage("happy.bmp");
  TFTscreen.image(emotive, 0, 0);
}

void loop() {
  // don't do anything if the image wasn't loaded correctly.
  if (emotive.isValid() == false) {
    return;
  }
}
