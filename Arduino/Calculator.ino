#include <LiquidCrystal.h> 
#include <Keypad.h> 


const byte ROWS = 4; // Four rows
const byte COLS = 4; // Three columns

// Define the Keymap
char keys[ROWS][COLS] = {

  {'1','2','3','A'},

  {'4','5','6','B'},

  {'7','8','9','C'},

  {'*','0','#','D'}

};

byte rowPins[ROWS] = { 6, 7, 8, 9 };// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte colPins[COLS] = { 10, 11, 12, 13 }; // Connect keypad COL0, COL1 and COL2 to these Arduino pins.

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); //  Create the Keypad

const int rs = 0, en = 1, d4 = 2, d5 = 3, d6 = 4, d7 = 5; //Pins to which LCD is connected
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


 long Num1,Num2,Number;
 char key,action;
 boolean result = false;

void setup() {
  lcd.begin(16, 2); //We are using a 16*2 LCD display
}

void loop() {
key = kpd.getKey();

if (key!=NO_KEY)
DetectButtons();

if (result==true)
CalculateResult();

DisplayResult(); 

}



void DetectButtons()
{ 
      lcd.clear(); //Then clean it
    if (key=='*') //If cancel Button is pressed
    {
     lcd.setCursor(0,0);
     lcd.print ("Button Cancel");
      Number=Num1=Num2=0; result=false;}

      
     if (key == '1') //If Button 1 is pressed
    {
    if (Number==0)
    Number=1;
    else
    Number = (Number*10) + 1; //Pressed twice
    }

     if (key == '4') //If Button 4 is pressed
    {
    if (Number==0)
    Number=4;
    else
    Number = (Number*10) + 4; //Pressed twice
    }
    
     if (key == '7') //If Button 7 is pressed
    {
    if (Number==0)
    Number=7;
    else
    Number = (Number*10) + 7; //Pressed twice
    } 

     if (key == '0')//Button 0 is Pressed
    { 
    if (Number==0)
    Number=0;
    else
    Number = (Number*10) + 0; //Pressed twice
    }

      if (key == '2') //Button 2 is Pressed
    {
     if (Number==0)
    Number=2;
    else
    Number = (Number*10) + 2; //Pressed twice
    }

    
  if (key == '5')
    {
     if (Number==0)
    Number=5;
    else
    Number = (Number*10) + 5; //Pressed twice
    }
    
     if (key == '8')
    {
     if (Number==0)
    Number=8;
    else
    Number = (Number*10) + 8; //Pressed twice
    }   


     if (key == '#')
    {
    Num2=Number;
    result = true;
    }
    
     if (key == '3')
    { 
     if (Number==0)
    Number=3;
    else
    Number = (Number*10) + 3; //Pressed twice
    }

         if (key == '6')
    {
    if (Number==0)
    Number=6;
    else
    Number = (Number*10) + 6; //Pressed twice
    }
    
     if (key == '9')
    {
    if (Number==0)
    Number=9;
    else
    Number = (Number*10) + 9; //Pressed twice
    }  

       if (key == 'A' || key == 'B' || key == 'C' || key == 'D') //Detecting Buttons on Column 4
  {
    Num1 = Number;    
    Number =0;
    if (key == 'A')
    { 
      action = '+';}
     if (key == 'B')
    {
      action = '-'; }
     if (key == 'C')
    { 
      action = '*';}
     if (key == 'D')
    {
      action = '/';}  
    }
        delay(100);
}

    void CalculateResult()
{
 
  if (action=='+')
    Number = Num1+Num2;

  if (action=='-')
    Number = Num1-Num2;

  if (action=='*')
    Number = Num1*Num2;

  if (action=='/')
    Number = Num1/Num2; 
}

void DisplayResult()
{
  lcd.setCursor(0, 0);   // set the cursor to column 0, line 1
  lcd.print(Num1); lcd.print(action); lcd.print(Num2); 
  
  if (result==true)
  {lcd.print(" ="); lcd.print(Number);} //Display the result
  
  lcd.setCursor(0, 1);   // set the cursor to column 0, line 1
  lcd.print(Number); //Display the result
}


  
  
    
