#include <SoftwareSerial.h>
SoftwareSerial blu(2, 3);// rx, tx
int led1=6;
int led2=7;
int state;


void setup()
{
  Serial.begin(9600);
  blu.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
}

void loop()
{
  while(blu.available())
  {
    state = blu.read();
    
    if (state=='0')
    {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
    }
    if (state=='1')
    {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
    }
        if (state=='2')
    {
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
    }
         if (state=='3')
    {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
    }
  }
}

