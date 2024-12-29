#include "SoftwareSerial.h"
SoftwareSerial blu(2, 3);
void setup() { 
 Serial.begin(9600); 
 blu.begin(9600); 
} 
void loop() 
{ 
 if (blu.available())
 {
   Serial.write(blu.read()); 
 }
 if (Serial.available())
 {
   blu.write(Serial.read());
 }
}
