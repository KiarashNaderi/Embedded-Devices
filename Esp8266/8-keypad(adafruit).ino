#include "config.h"

AdafruitIO_Feed * LED = io.feed("keypad");
int i;
int leds[6] = {D0,D1,D2,D3,D5,D6};
void setup() {
  Serial.begin(115200);
  io.connect();

  while(io.status() < AIO_CONNECTED){
    Serial.println(".");
    delay(500);
  }
  Serial.println(io.statusText());
////////////
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  pinMode(D3,OUTPUT);
  pinMode(D5,OUTPUT);
  pinMode(D6,OUTPUT);
  LED->onMessage(turnon);
}

void loop() {
  io.run();
  digitalWrite(leds[i],HIGH);
}

void turnon(AdafruitIO_Data * in){
  int number = in->toInt();
  i = number;
  Serial.println(i);
}
