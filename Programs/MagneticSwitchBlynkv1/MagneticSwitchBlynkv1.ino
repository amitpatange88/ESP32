/*************************************************************
Author : Amit Patange
/* Comment this out to disable prints and save space 
*************************************************************/
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
BlynkTimer timer;

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "0d2f3135325d420291ce2860079542ac";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "ja simaran jeele apani jndagi";
char pass[] = "atom@realsteel";
int flag=0;
const int DPin = 13;
String formattedDate;
void setup()
{
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);

  //setup notification button on pin D13
  pinMode(DPin, INPUT_PULLUP);

  timeClient.begin();
  // Initialize a NTPClient to get time
  timeClient.begin();
  // Set offset time in seconds to adjust for your timezone, for example:
  // GMT +1 = 3600
  // GMT +8 = 28800
  // GMT -1 = -3600
  // GMT 0 = 0
  timeClient.setTimeOffset(19800);

  //every 10sec it will call this function and checks if button is pressed or not. 
  timer.setInterval(1000L, NotifyOnButtonPress);
}

void NotifyOnButtonPress()
{
  int DoorStatus = digitalRead(DPin);
  ProcessDateTimeOnNTPServer();
  formattedDate = timeClient.getFormattedDate();

  //When door is opened.
  if(DoorStatus == 1 && flag == 0)
  {
    flag=1;
    Blynk.notify("Security Breach : Someone has just opened the G-502 door. Please take care of your house. Stamp DateTime : "+formattedDate);
  }
  else if(DoorStatus == 0 && flag==1)
  {
    flag=0;
    Blynk.notify("Security Breach : Now the G-502 door has been closed.  Stamp DateTime : "+formattedDate);
  }
}

void ProcessDateTimeOnNTPServer()
{   
  while(!timeClient.update()) {
    timeClient.forceUpdate();
  }
}

void loop()
{ 
  Blynk.run();
  timer.run();
}
