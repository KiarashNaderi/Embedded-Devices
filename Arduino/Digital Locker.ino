#include <LiquidCrystal.h> 
#include <Keypad.h> 
#include<EEPROM.h>
 // ramz feli 2323

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

//Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); //  Create the Keypad

const int rs = 0, en = 1, d4 = 2, d5 = 3, d6 = 4, d7 = 5; //Pins to which LCD is connected
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


char password[4];
char pass[4],pass1[4];
int i=0;
char customKey=0;
Keypad customKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS); 
void setup() {
  lcd.begin(16, 2); 
  lcd.setCursor(0,0);
  lcd.print("  digital lock ");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Enter password");
  lcd.setCursor(0,1);
  
  for(int j=0;j<4;j++)
  EEPROM.write(j, j+49);// 1 2 3 4
  for(int j=0;j<4;j++)
  pass[j]=EEPROM.read(j);
}

void loop() {
   
  customKey = customKeypad.getKey();
  if(customKey=='#')
  change();
    if (customKey)
  {
     password[i++]=customKey;
     lcd.print(customKey);
  }
    if(i==4)
  {
    delay(200);
    for(int j=0;j<4;j++)
    pass[j]=EEPROM.read(j);
    if(!(strncmp(password, pass,4)))
        {
      lcd.clear();
      lcd.print("correct");
      delay(2500);
      lcd.setCursor(0,1);
      lcd.print("Change password");
      delay(2000);
      lcd.clear();
      lcd.print("Enter password");
      lcd.setCursor(0,1);
      i=0;
    }
      else
    {
      lcd.clear();
      lcd.print("false");
      lcd.setCursor(0,1);
      lcd.print("Change password");
      delay(2000);
      lcd.clear();
      lcd.print("Enter Password");
      lcd.setCursor(0,1);
      i=0;

    }
  }
}
void change()
{
  int j=0;
  lcd.clear();
  lcd.print("your pass");
  lcd.setCursor(0,1);
  while(j<4)
  {
    char key=customKeypad.getKey();
    if(key)
    {
      pass1[j++]=key;
      lcd.print(key);

    }
    key=0;
  }
   delay(500);
  
  if((strncmp(pass1, pass, 4)))
  {
    lcd.clear();
    lcd.print("false");
    lcd.setCursor(0,1);
    lcd.print("Enter again");
    delay(1000);
  }
  else
  {
    j=0;
    
  lcd.clear();
  lcd.print("Enter New Pass");
  lcd.setCursor(0,1);
  while(j<4)
  {
char key=customKeypad.getKey();
    if(key)
    {
      pass[j]=key;
      lcd.print(key);
      EEPROM.write(j,key);
      j++;
 
    }
  }
  lcd.print("  finish ");
  delay(1000);
  }
  lcd.clear();
  lcd.print("Enter your pass");
  lcd.setCursor(0,1);
  customKey=0;
}

  
