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
#include <Arduino_LSM6DS3.h>  // Library: https://www.arduino.cc/en/Reference/ArduinoLSM6DS3
#include "secrets.h"

void push_accelerometer_values();

void setup()
{
  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }

  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
  push_accelerometer_values();
}

void push_accelerometer_values()
{
  float x, y, z;

  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);

    Serial.print(x);
    Blynk.virtualWrite(V1, x);
    Serial.print('\t');
    Serial.print(y);
    Blynk.virtualWrite(V2, y);
    Serial.print('\t');
    Serial.println(z);
    Blynk.virtualWrite(V3, z);
  }
}
