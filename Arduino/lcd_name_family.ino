#include <LiquidCrystal.h>
LiquidCrystal lcd(0, 1, 8, 9, 10, 11); // پیکربندی ال سی دی

void setup()
{
lcd.begin(16, 2);
}
void loop()
{
lcd.setCursor(0, 0);
lcd.print("kiarash");
lcd.setCursor(0, 1);
lcd.print("Naderi");
delay(1500);
lcd.scrollDisplayRight();


}
