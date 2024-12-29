#include "config.h"

AdafruitIO_Feed * ON=io.feed("on");
AdafruitIO_Feed * OFF=io.feed("off");
int led=D1; 

void setup() {
  Serial.begin(115200);
  io.connect();

  while(io.status() < AIO_CONNECTED){
    Serial.println(".");
    delay(500);
  }
  Serial.println(io.statusText());
////
  pinMode(led,OUTPUT);
  ON->onMessage(f1); // tabe f1 ejra mishavad agar az feed ON data daryaft shavad
  OFF->onMessage(f2); // tabe f2 ejra mishavad agar az feed OFF data daryaft shavad
  ON->get();
  OFF->get();
}

void loop() {
  io.run();
}

void f1(AdafruitIO_Data *in){
  digitalWrite(led,HIGH);
}

void f2(AdafruitIO_Data *in){
  digitalWrite(led,LOW);
}
