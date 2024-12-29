int led=2;
int key=3;
bool state=LOW;

void setup() {
pinMode(led,OUTPUT);
pinMode(key,INPUT);
attachInterrupt(digitalPinToInterrupt(key),led_control,CHANGE);
}

void loop() {
 digitalWrite(led,state);

}
void led_control(){
state=!state;

}