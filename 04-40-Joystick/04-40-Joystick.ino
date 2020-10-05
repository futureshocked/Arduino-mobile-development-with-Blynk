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
#include <Servo.h>

Servo myservo1;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  myservo1.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(10);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  Blynk.run();

}

void control_servo1(int pos)
{
  myservo1.write(pos);
}

void control_servo2(int pos)
{
  myservo2.write(pos);
}

BLYNK_WRITE(V1) //Button Widget is writing to pin V1
{
  Serial.print("V1: ");
  Serial.println(param.asInt());
  control_servo1(param.asInt());
}

BLYNK_WRITE(V2) //Button Widget is writing to pin V2
{
  Serial.print("V2: ");
  Serial.println(param.asInt());
  control_servo2(param.asInt());
}

// If using "merge" mode, values come bundled in an array
BLYNK_WRITE(V3) //Button Widget is writing to pin V3
{
  Serial.print("V3: ");
  Serial.print(param[0].asInt());
  Serial.print(", ");
  Serial.println(param[1].asInt());

  control_servo1(param[0].asInt());
  control_servo2(param[1].asInt());
}
