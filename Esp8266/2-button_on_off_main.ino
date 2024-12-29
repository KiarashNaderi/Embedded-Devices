int buzzer=D1;
int button=D2;
int state;
void setup() {
pinMode(LED,OUTPUT);
pinMode(button,INPUT_PULLUP);
}

void loop() {
state=digitalRead(button);
if (state==LOW){
digitalWrite(buzzer,HIGH);
}
else{
  digitalWrite(buzzer,LOW);
}
delay(500);
}