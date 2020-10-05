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

void led_pwm(int pwm_value);

byte pwm_pin = 2;

BLYNK_WRITE(V1) //Button Widget is writing to pin V1
{
  led_pwm(param.asInt());
}

void setup()
{
  // Debug console
  Serial.begin(9600);
  
  pinMode(pwm_pin, OUTPUT);

  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}

void led_pwm(int pwm_value)
{
  analogWrite(pwm_pin, pwm_value);
}
