/*
 * project : photo resistor
 * name : Mihaela Petkova
 * date : 18.02.2018
 */

int lightPin = 1;  //define a pin for Photo resistor
int ledPin=13;     //define a pin for LED

void setup()
{
    Serial.begin(9600);  
    pinMode( ledPin, OUTPUT );
}

void loop()
{
    Serial.println(analogRead(lightPin)); 
    analogWrite(ledPin, analogRead(lightPin)/4); 
    
    
    delay(1000);
}
