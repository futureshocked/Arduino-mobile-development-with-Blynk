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

WidgetTerminal terminal(V0);

BlynkTimer timer;

void setup()
{
  Blynk.begin(auth, ssid, pass);

  terminal.clear();
  terminal.println("Staring the sensor...");
  if (!tempsensor.begin(0x18)) {
    terminal.println("Couldn't find MCP9808! Check your connections and verify the address is correct.");
    terminal.flush();
    while (1);
  }
  terminal.println("Started.");

  tempsensor.setResolution(3);

  timer.setInterval(1000L, update_lcd);
}

void loop()
{
  Blynk.run();
  timer.run();
}

void update_lcd()
{
  terminal.print(tempsensor.readTempC());
  terminal.print(" °C, ");
  terminal.print(tempsensor.readTempF());
  terminal.println(" °F");
}
