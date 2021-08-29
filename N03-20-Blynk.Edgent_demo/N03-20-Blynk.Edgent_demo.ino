/*  Arduino Mobile Development With Blynk
   This code is part of a course from Tech Explorations.
   For information about this course, please see
   https://techexplorations.com/so/blynk/
   For information on hardware components and the wiring needed to
   run this sketch, please see the relevant lecture in the course.
    Created by Peter Dalmaris
*/
// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "--your-blynk-template-id"
#define BLYNK_DEVICE_NAME "--your-device-name--"

#define BLYNK_FIRMWARE_VERSION        "0.1.7"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_WROVER_BOARD
//#define USE_TTGO_T7

#include "BlynkEdgent.h"

BlynkTimer timer;

void randomNumberCallback() {
  int random_number = random(300);
  Blynk.virtualWrite(V1, random_number);
  if (random_number > 290)
  {
    Blynk.logEvent("randomnumberreceived", random_number);  //Beware, there
    // is a limit of 100 events per device per day.
    Serial.print("Event sent Cloud: ");
    Serial.println(random_number);
  }
}

BLYNK_WRITE(V0) // Executes when the value of virtual pin 0 changes
{
  Serial.println(param.asInt());
  if (param.asInt() == 1)
  {
    // execute this code if the switch widget is now ON
    digitalWrite(23, HIGH); // Set digital pin 23 HIGH
    Blynk.virtualWrite(V3, 1); // Using plain virtual pin number
  }
  else
  {
    // execute this code if the switch widget is now OFF
    digitalWrite(23, LOW); // Set digital pin 23 LOW
    Blynk.virtualWrite(V3, 0); // Using plain virtual pin number
  }
}

// Not using GPIO 22 because I have assigned it to Blynk's status LED (settings.h)
//BLYNK_WRITE(V2) // Executes when the value of virtual pin 2 changes
//{
//  Serial.println(param.asInt());
//  if (param.asInt() == 1)
//  {
//    // execute this code if the switch widget is now ON
//    digitalWrite(22, HIGH); // Set digital pin 23 HIGH
//  }
//  else
//  {
//    // execute this code if the switch widget is now OFF
//    digitalWrite(22, LOW); // Set digital pin 23 LOW
//  }
//}

void setup()
{
  randomSeed(analogRead(0));
  Serial.begin(115200);
  delay(100);

  pinMode(23, OUTPUT);

  timer.setInterval(1000L, randomNumberCallback);

  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
  timer.run(); // Initiates BlynkTimer
}
