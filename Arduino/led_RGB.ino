int red=11;
int green=10;
int blue=9;

void setup() {
pinMode(red,OUTPUT);
pinMode(blue,OUTPUT);
pinMode(green,OUTPUT);

}

void loop() {
digitalWrite(red,HIGH);
digitalWrite(green,LOW);
digitalWrite(blue,LOW);
delay(1000);
digitalWrite(red,LOW);
digitalWrite(green,HIGH);
digitalWrite(blue,LOW);
delay(1000);
digitalWrite(red,LOW);
digitalWrite(green,LOW);
digitalWrite(blue,HIGH);
delay(1000);

}
