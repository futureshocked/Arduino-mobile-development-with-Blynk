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
    notify_temperature();
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

void notify_temperature()
{
  float temperatureC = tempsensor.readTempC();

  String notification_body = "";
  notification_body += "From {DEVICE_NAME}: the current temperature is ";
  notification_body += String(temperatureC);
  notification_body += " °C.";

  Serial.println("Sending this notification body: ");
  Serial.println(notification_body);

  Blynk.notify(notification_body);

  digitalWrite(ext_led, LOW);
}
