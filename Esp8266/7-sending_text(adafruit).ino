#include "config.h"

AdafruitIO_Feed *TEXT = io.feed("text");

void setup() {
  Serial.begin(115200);
  io.connect();

  while(io.status() < AIO_CONNECTED){
    Serial.println(".");
    delay(500);
  }
  Serial.println(io.statusText());
////
  pinMode(D1,INPUT_PULLUP);

}

void loop() {
  io.run();
  if (digitalRead(D1) == LOW){
    TEXT->save("key is pressed"); // ersal data az nodemcu az adafruit
   // delay(1000);
  }

}
