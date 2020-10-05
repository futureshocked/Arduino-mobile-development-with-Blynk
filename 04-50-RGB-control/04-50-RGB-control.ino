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

// You can assign the Blynk zeRGBa widget to pins directly from the app.
// If you do that, you do not need to set pins and write any more code in
// the sketch.
// If you choose to use merge mode, you will need to write the matching code
// as per the example below.

int green_pin = 6;
int blue_pin = 5;
int red_pin = 3;

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
}

BLYNK_WRITE(V1) //Button Widget is writing to pin V1
{
  Serial.print("V1: ");
  Serial.print(param[0].asInt());
  Serial.print(",");
  Serial.print(param[1].asInt());
  Serial.print(",");
  Serial.println(param[2].asInt());

  analogWrite(red_pin, param[0].asInt());
  analogWrite(green_pin, param[1].asInt());
  analogWrite(blue_pin, param[2].asInt());
}
