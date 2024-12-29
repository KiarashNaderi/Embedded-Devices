#include <SoftwareSerial.h>
int led=6;
int lastState = 0;
SoftwareSerial bluetooth(2, 3);

void setup()
{
  Serial.begin(38400);
  bluetooth.begin(38400);
  pinMode(led, OUTPUT);
  digitalWrite(led,lastState);
}

void loop()
{
  if (bluetooth.available() > 0)
  {
    int message = bluetooth.read();
    message -= 48;
    if (message != lastState)
    {
      digitalWrite(led, message);
      lastState = message;
    }
  }
}
