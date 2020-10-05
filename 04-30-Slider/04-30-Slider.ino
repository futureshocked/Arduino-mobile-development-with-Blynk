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

// You can assign the Step Control widget to a pin directly from the app.
// If you do that, you do not need to set pins and write any more code in
// the sketch.

void setup() {
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
}
