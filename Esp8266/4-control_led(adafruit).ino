#include "config.h"
int led=D1;

AdafruitIO_Feed *key=io.feed("LED");  // AdafruitIO_Feed *baraye arduino = io.feed("name baraye platform");

void setup() {
Serial.begin(115200);  // serial monitor ba sorate bala
io.connect(); // etesal nodemcu be adafruite

while(io.status() < AIO_CONNECTED){  //etesal  be adafruite shavad az while kharej mishavad 
Serial.println(".");
delay(500);
}
Serial.println(io.statusText());  // etesal bargharar bashad yek matn minevisad

pinMode(led,OUTPUT);
key->onMessage(code); //adafruite be nodemcu data befrastad tabea ejra shavad  
key->get(); // data az feed gerefte shavad
 
}

void loop() {
  io.run(); // tabadole data
}
// tarife tabe
void code(AdafruitIO_Data *in){  //dataye adafruite ra dar in gharar midim
  int state = in->toInt(); 
  digitalWrite(led,state);
}
