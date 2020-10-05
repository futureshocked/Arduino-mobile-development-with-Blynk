/*  Arduino Mobile Development With Blynk

   This code is part of a course from Tech Explorations.
   For information about this course, please see

   https://techexplorations.com/so/blynk/

   For information on hardware components and the wiring needed to
   run this sketch, please see the relevant lecture in the course.

    Created by Peter Dalmaris
*/

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "--BLYNK YOUR AUTH TOKEN--";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "--YOUR SSID--";
char pass[] = "--YOUR WIFI PASSWORD--";

// Your Blynk server IP and port.
// This may be local network IP, or the public network IP.
// If you use the public network IP, ensure that you have 
// setup port forwarding in your router.
IPAddress blynk_ip(123,123,123,123);  // Replace "123" with the actual IP
                                      // address segments.
int blynk_port = 8080;
