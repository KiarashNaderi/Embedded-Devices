int led=2;
bool flag=0;
const int SW = 3;
const int X_pin = A0;
const int Y_pin = A1;
int vol=250;
void setup() {
 pinMode(led, OUTPUT);
 pinMode(SW, INPUT_PULLUP);

}

void loop() {
  Serial.begin(9600);
  if(flag==0){
 digitalWrite(led,HIGH);
  delay(vol);
  digitalWrite(led,LOW);
  delay(vol);
  }
Serial.print(vol);
  int position_x = analogRead(X_pin);
  int position_y = analogRead(Y_pin);
    int reset = digitalRead(SW);
 if (position_y >= 550) {
  if(vol<=50)
  vol=50;
  else 
  vol=vol-50;
}

 if (position_y <=450) {
  vol=vol+50;
 }
if( reset==LOW){
  digitalWrite(led,HIGH);
  //flag=~flag;
}
//else
//flag=0;

 
}
