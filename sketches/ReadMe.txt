November 2017
Tutorial: How to make a *.hex sketch for use in a C# runtime.

Using the Arduino IDE, version here 1.8.4, create a sketch which encapsulates the particular desired expression of emotion, such as:
	1. Happy,
	2. Laugh, 
	3. Sad,
	4. Upset,
	5. Content.
The following example code of filetype *.ino, for the emotion "content":

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
  emotive = TFTscreen.loadImage("content.bmp");
  TFTscreen.image(emotive, 0, 0);
}

void loop() {
  // don't do anything if the image wasn't loaded correctly.
  if (emotive.isValid() == false) {
    return;
  }
}

Can be compiled into the correct Intel format for the Uploader library by

Sketch --> Verify/Compile
Sketch --> Export compiled binary

where a *.hex file will be created in the same folder as the source file.

Place these in the "sketches" folder in the GUI. The naming should be kept the same and if an additional emotion or sequence is required, add to the switch statement on the form, on the method: public void SetEmotiveDisplay(string emotion).

It would be interesting to see how sophisticated these can be made, in the matter of animated emotional display sequences.