/*  Arduino Mobile Development With Blynk

   This code is part of a course from Tech Explorations.
   For information about this course, please see

   https://techexplorations.com/so/blynk/

   For information on hardware components and the wiring needed to
   run this sketch, please see the relevant lecture in the course.

    Created by Peter Dalmaris
*/

#include <SPI.h>
#include <WiFiNINA.h>
#include <BlynkSimpleWiFiNINA.h>
#include "secrets.h"
#include "Adafruit_MCP9808.h"
#include <Arduino_LSM6DS3.h>

Adafruit_MCP9808 tempsensor = Adafruit_MCP9808();

BlynkTimer timer;

void push_accelerometer_values();

void setup()
{
  Serial.begin(9600);
  Serial.println("Starting the temperature sensor");
  if (!tempsensor.begin(0x18)) {
    Serial.println("Couldn't find MCP9808! Check your connections and verify the address is correct.");
    while (1);
  }
  Serial.println("Started");

  tempsensor.setResolution(3);

  Serial.println("Starting the accelerometer");
  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }

  Serial.println("Started");
  
//  Blynk.begin(auth, ssid, pass);
  Blynk.begin(auth, ssid, pass, blynk_ip, blynk_port);
  timer.setInterval(1000L, update_superchart);

}

void loop()
{
  Blynk.run();
  timer.run();
  push_accelerometer_values();
}

void update_superchart()
{
  Blynk.virtualWrite(V0, tempsensor.readTempC());
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
