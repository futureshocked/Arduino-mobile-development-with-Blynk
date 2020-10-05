/*  Arduino Mobile Development With Blynk

   This code is part of a course from Tech Explorations.
   For information about this course, please see

   https://techexplorations.com/so/blynk/

   For information on hardware components and the wiring needed to
   run this sketch, please see the relevant lecture in the course.

    Created by Peter Dalmaris
*/

#define BLYNK_PRINT Serial

#include <SPI.h>
#include <WiFiNINA.h>
#include <BlynkSimpleWiFiNINA.h>
#include "secrets.h"

BlynkTimer timer; // Create a Timer object called "timer"!

// You can assign the Button widget to a pin directly from the app.
// If you do that, you do not need to set pins and write any more code in
// the sketch.

#define POT_VIRTUAL_PIN V1
#define pot_pin A0

void setup() {
  //Begin serial communication with monitor
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);

  timer.setInterval(1000L, sendUptime); //  Here you set interval (1sec) and which function to call
}

void sendUptime()
{
  // This function sends Arduino up time every 1 second to Virtual Pin (V1)
  // In the app, Widget's reading frequency should be set to PUSH
  // You can send anything with any interval using this construction
  // Don't send more that 10 values per second

  Blynk.virtualWrite(POT_VIRTUAL_PIN, analogRead(pot_pin));
}

void loop() {
  Blynk.run(); // all the Blynk magic happens here
  timer.run(); // BlynkTimer is working...
}
