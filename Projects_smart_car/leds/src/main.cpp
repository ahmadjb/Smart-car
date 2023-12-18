/*************************************************************

  This is a simple demo of sending and receiving some data.
  Be sure to check out other examples!
 *************************************************************/

// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID           "TMPLTjpHivRI"
#define BLYNK_DEVICE_NAME           "Quickstart Device"
#define BLYNK_AUTH_TOKEN            "UtMrh5j8ZXhdnHTt8EcG5q51BdCVo205"


// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial

#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
 #include <DNSServer.h>
 #include "MotoreDriver.h"
 

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "DENEEZ";
char pass[] = "Tt123456";

BlynkTimer timer;

// This function is called every time the Virtual Pin 0 state changes
BLYNK_WRITE(V0)
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();
  

  // Update state
  Blynk.virtualWrite(V1, value);
 // digitalWrite(D0, value);
 Serial.println(V0);
  
  // setSpeedMotore(value);
  

}
BLYNK_WRITE(V6)
{
  int speed = param.asInt();
  setSpeedMotore(speed);
    
   
}

BLYNK_WRITE(V9)
{
    int x = param[0].asInt()-512;
    Serial.print("X axis:");
    Serial.println(x);
    setX(x);
  
   //moveControlFB();
   
}
BLYNK_WRITE(V10)
{
  
    int y = param[0].asInt()-512;
    Serial.print("y axis:");
    Serial.println(y);
    setY(y);
   
}
BLYNK_WRITE(V13)
{
  int red = param.asInt();
      setcolor1(red);
}
BLYNK_WRITE(V14)
{

   int blue = param.asInt() ;
       setcolor3(blue);
 
   
}
BLYNK_WRITE(V15)
{
   int green = param.asInt() ;
      setcolor2(green);
}
BLYNK_WRITE(V18)
{
  
    int led = param.asInt();
    setled(led);
   
}



// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED()
{
  // Change Web Link Button message to "Congratulations!"
  Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  Blynk.setProperty(V3, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
  Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}

// This function sends Arduino's uptime every second to Virtual Pin 2.
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V2, millis() / 1000);
  Blynk.virtualWrite(V4, analogRead(D0));
  
  //Serial.println(value);
}

void setup()
{
  // Debug console
  Serial.begin(9600);
  initMotores();
  Controler_ColorSensor(D0,200);
  

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);

  // Setup a function to be called every second
  timer.setInterval(1000L, myTimerEvent);
   
}

void loop()
{
  Blynk.run();
  timer.run();
  updateMotore();
 //Serial.println("okkkkkkkkkkkkkkkkkkkkkkkkkkkk");
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
  //digitalWrite(D0, HIGH);
  //delay(1000); // Wait for 1000 millisecond(s)
  //digitalWrite(D0, LOW);
  //delay(1000); // Wait for 1000 millisecond(s)
}
