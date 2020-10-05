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

Adafruit_MCP9808 tempsensor = Adafruit_MCP9808();

BlynkTimer timer;

void setup()
{
  Serial.begin(9600);
  if (!tempsensor.begin(0x18)) {
    Serial.println("Couldn't find MCP9808! Check your connections and verify the address is correct.");
    while (1);
  }

  tempsensor.setResolution(3);

  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, update_superchart);

}

void loop()
{
  Blynk.run();
  timer.run();
}

void update_superchart()
{
  Blynk.virtualWrite(V0, tempsensor.readTempC());
}
