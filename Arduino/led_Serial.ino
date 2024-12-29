int led=3;
int stati;
int flag=0;
void setup() {
  Serial.begin(9600);
  
}

void loop() {
 while(Serial.available() > 0) {
stati = Serial.parseInt ();
if (flag==1){
   digitalWrite(led,HIGH);
   if(stati==9){
    flag=0;
   }
  }
else{
  Serial.println("LED is OFF");
  digitalWrite(led,LOW);
}
  if(stati==1){
    flag=1;
  Serial.println("LED is On");
}

}
}
