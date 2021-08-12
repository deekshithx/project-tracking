#include <SoftwareSerial.h>
#include<LiquidCrystal.h>
#include<Wire.h>
#include<MQTT.h>
#include <TinyGPS.h> 
#include <NMEAGPS.h>
#include <GPSport.h>
#include <TimeLib.h>
#include "PF.h"
#include "PetitSerial.h"

String inputString = "";
String fromGSM = "";
SoftwareSerial mySerial(3, 2);
char sim800l[255];
int sim800lIndex = 0;
float lat,lon; // create variable for latitude and longitude object  
SoftwareSerial gpsSerial(3,4);//rx,tx 
LiquidCrystal lcd(A0,A1,A2,A3,A4,A5); 
TinyGPS gps;
define UTC_OFFSET 1  // set time zone offset, i.e. 1 = UTC+1
define TXPin 8       // SIM900 Tx pin
define RXPin 9       // SIM900 Rx pin
define PWRPin 7      // SIM900 software power pin


void setup()
{
Serial.begin(9600);
mySerial.begin(9600);
inputString.reserve(200);
fromGSM.reserve(200);
Serial.println(" Command --> AT ");
mySerial.print("AT");
mySerial.print("\r");
delay(100);
Serial.print("Starting BBT");
while (mySerial.available())
{
sim800l[sim800lIndex] = mySerial.read();
sim800lIndex++;
Serial.print( sim800l[sim800lIndex - 1]);
}

sim800lIndex = 0;
delay(100);
while (mySerial.available())

{
sim800l[sim800lIndex] = mySerial.read();
sim800lIndex++;
Serial.print( sim800l[sim800lIndex - 1]);
}

sim800lIndex = 0;
delay(100);
while (mySerial.available())
{
sim800l[sim800lIndex] = mySerial.read();
sim800lIndex++;
Serial.print( sim800l[sim800lIndex - 1]);
}
sim800lIndex = 0;
while ( !(mySerial.available()) );
while (mySerial.available())
{
sim800l[sim800lIndex] = mySerial.read();
sim800lIndex++;
Serial.print( sim800l[sim800lIndex - 1]);
}
sim800lIndex = 0;
}

void loop()
    while(gpsSerial.available()){ 
  if(gps.encode(gpsSerial.read()))
  {  
  gps.f_get_position(&lat,&lon);
{
while (1)
{

while (mySerial.available())
{
sim800l[sim800lIndex] = mySerial.read();
sim800lIndex++;
if (sim800l[sim800lIndex - 4] == 'R' && sim800l[sim800lIndex - 3] == 'I' && sim800l[sim800lIndex - 2] == 'N' && sim800l[sim800lIndex - 1] == 'G')
{
delay(8000);
  while (Serial.available())
{
sim800l[sim800lIndex] = Serial.read();
sim800lIndex++;
mySerial.print( sim800l[sim800lIndex - 1]);
Serial.println("Connected");
}

}
Serial.print("BBT is Online");
}
}
}
