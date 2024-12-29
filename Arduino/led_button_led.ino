 int button =7;     
 int led =2;      
 int buttonState;      

void setup() {
  pinMode(led, OUTPUT);      
  pinMode(button, INPUT);     
}

void loop(){
   buttonState = digitalRead(button);
  if (buttonState == LOW) {         
    digitalWrite(led, HIGH);  
  } 
  else {
    digitalWrite(led, LOW); 
  }
}
