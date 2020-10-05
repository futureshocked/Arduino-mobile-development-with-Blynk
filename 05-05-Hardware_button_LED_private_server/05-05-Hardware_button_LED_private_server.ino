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

int button_pin = 9;
int ext_led = 2;
WidgetLED led1(V0);

void setup()
{
  Serial.begin(9600);
  pinMode(button_pin, INPUT);     // set button pin to input
  digitalWrite(button_pin, HIGH); // turn on pullup resistors
  pinMode(ext_led, OUTPUT);

  //  Blynk.begin(auth, ssid, pass);
  Blynk.begin(  auth, 
                ssid, 
                pass, 
                IPAddress(192, 168, 111, 70),     // Change this IP for the
                8080);                            // actual IP address of
                                                  // your Blynk Server.    
                                                      
  Serial.println("Started");
}

void loop()
{
  Blynk.run();

  if (digitalRead(button_pin) == LOW)
  {
    led1.on();
    digitalWrite(ext_led, HIGH);
    Serial.println("Pressed");
  }
  else
  {
    led1.off();
    digitalWrite(ext_led, LOW);
    Serial.println("Not Pressed");
  }
}
