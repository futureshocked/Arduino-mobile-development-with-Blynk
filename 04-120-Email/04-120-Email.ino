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
int ext_led = 2;

BLYNK_WRITE(V0) //Button Widget is writing to pin V0
{
  int pinData = param.asInt();
  if (pinData == HIGH)
  {
    digitalWrite(ext_led, HIGH);
    email_temperature();
  }
}

void setup()
{
  Serial.begin(9600);
  if (!tempsensor.begin(0x18)) {
    Serial.println("Couldn't find MCP9808! Check your connections and verify the address is correct.");
    while (1);
  }
  Serial.println("Started.");
  pinMode(ext_led, OUTPUT);
  tempsensor.setResolution(3);

  Blynk.begin(auth, ssid, pass);

}

void loop()
{
  Blynk.run();
}

void email_temperature()
{
  float temperatureC = tempsensor.readTempC();

  String email_body = "";
  email_body += "The current temperature is ";
  email_body += String(temperatureC);
  email_body += " °C";

  Serial.println("Sending this email body: ");
  Serial.println(email_body);

  Blynk.email("peter@txplore.com", "Temperature update from {DEVICE_NAME}", email_body);

  digitalWrite(ext_led, LOW);
}
