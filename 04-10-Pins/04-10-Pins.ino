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

int pot_pin = 0;    // Analog pin
int ext_led = 2;    // Digital pin
int button_pin = 9; // Digital pin

WidgetLED led1(V0);

void setup()
{
  Serial.begin(9600);
  pinMode(ext_led, OUTPUT);
  pinMode(button_pin, INPUT);     // set button pin to input
  digitalWrite(button_pin, HIGH); // turn on pullup resistors

  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();

  int pot_value = analogRead(pot_pin);
  int scaled_pot_value = map(pot_value, 0, 1023, 0, 255);
  led1.setValue(scaled_pot_value);
  analogWrite(ext_led, scaled_pot_value);
  Serial.print(pot_value);
  Serial.print(", ");
  Serial.println(scaled_pot_value);
  delay(1);
}
