#include "config.h"  // farakhanie file config.h

void setup() {
  Serial.begin(115200);  
  io.connect();  

  while(io.status() < AIO_CONNECTED){
    Serial.println(".");
    delay(500);
  }
  Serial.println(io.statusText());


}

void loop() {
  io.run();
}
