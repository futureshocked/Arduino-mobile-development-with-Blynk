/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on ESP32 chip.

  Note: This requires ESP32 support package:
    https://github.com/espressif/arduino-esp32

  Please be sure to select the right ESP32 module
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill-in your Template ID (only if using Blynk.Cloud) */
#define BLYNK_TEMPLATE_ID "--your-blynk-template-id"
#define BLYNK_DEVICE_NAME "--your-device-name--"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "--your-ssid--";
char pass[] = "--your-wifi-password--";

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "--your-auth-token--";

byte led1_pin = 23;

void setup()
{
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);

  pinMode(led1_pin, OUTPUT);

  Serial.println("ESP32 2 started.");
}

BLYNK_WRITE(V0) // Executes when the value of virtual pin 0 changes
{
  Serial.println(param.asInt());
  if (param.asInt() == 1)
  {
    // execute this code if the switch widget is now ON
    digitalWrite(led1_pin, HIGH); // Set digital pin 23 HIGH
    Blynk.virtualWrite(V1, 1);
    Serial.println("LED is ON");
  }
  else
  {
    // execute this code if the switch widget is now OFF
    digitalWrite(led1_pin, LOW); // Set digital pin 23 LOW
    Blynk.virtualWrite(V1, 0);
    Serial.println("LED is OFF");
  }
}

void loop()
{
  Blynk.run();
}
