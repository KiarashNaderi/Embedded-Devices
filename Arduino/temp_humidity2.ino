#include <dht.h>
#define dataPin 8 // Defines pin number to which the sensor is connected
dht DHT; // Creats a DHT object
 
void setup() 
{
    Serial.begin(9600);
}
void loop() 
{
    
    //int readData = DHT.read22(dataPin); // DHT22/AM2302
    int readData = DHT.read11(dataPin); // DHT11
 
    float t = DHT.temperature; // Gets the values of the temperature
    float h = DHT.humidity; // Gets the values of the humidity
 
    // Printing the results on the serial monitor
    //temperature
    Serial.print("Temperature = ");
    Serial.print(t);
    Serial.print(" ");

    Serial.print((t * 9.0) / 5.0 + 32.0);//print the temperature in Fahrenheit
    Serial.print(" ");
    Serial.println("F ");// we go to the next line after println
    // humidity
    Serial.print("Humidity = ");
    Serial.print(h);
    Serial.println(" % ");
    Serial.println("");
 
    delay(2000); // Delays 2 secods
}
