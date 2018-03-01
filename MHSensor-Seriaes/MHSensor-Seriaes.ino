    /*
     * project by Mihaela Petkova;
     * project name is Pot-primrose;
     * date 11.02.2018;
     */
     
    const int sensorPin = A0; // select the input pin for the potentiometer
    int ledPin = 13; // select the pin for the LED
    int sensorValue = 0; // variable to store the value coming from the sensor
    
    int photoPin = 1; // analog pin by na pn1127
    int minLight; // min stoynost za light
    int maxLight; // max stoynost na light
    int light_level;
    int adjustedLightLevel;
    
    const int pinOut = 10;
    const int Moisture_level = 250;
  void setup ()
    {
      Serial.begin (9600);
      
      pinMode (ledPin, OUTPUT);
      pinMode(13,OUTPUT);
      pinMode(7,OUTPUT);
  
      light_level = analogRead(photoPin);
      minLight = light_level - 20;
      maxLight = light_level;
    }
    
  void LedState(int state)
    {
      digitalWrite(13,state);
    }
    
  void loop() 
    {    
      sensorValue = analogRead (sensorPin);
      sensorValue = constrain (sensorValue, 400, 1023);
      // ot 400 do 1023 zapazva;
      
      sensorValue = map(sensorValue, 400, 1023, 100, 0);
      digitalWrite (ledPin, HIGH);
      delay (sensorValue);
      
      digitalWrite (ledPin, LOW);
      delay (sensorValue);
      
      Serial.print("Soil humidity: ");
      Serial.println (sensorValue);
      
      int moisture = analogRead(sensorPin);
      Serial.print("Moisture=");
      Serial.println(moisture);
      //delay(100);
      
      
      if(moisture>Moisture_level){
        LedState(HIGH);
        digitalWrite(7,HIGH);
        }
      else{
        LedState(LOW);
        digitalWrite(7,LOW);
        }
    digitalWrite(7, LOW); // turn the relay off to start
       delay(3000); // wait for 3 seconds
       digitalWrite(7, HIGH); // turn the relay on to turn on 
       delay(3000); // wait for 3 seconds 
  
       
       light_level = analogRead(photoPin);
       if (minLight>light_level)
        {
          minLight = light_level;  
        }
        if (maxLight<light_level)
        {
          maxLight = light_level;  
        }      
       
        adjustedLightLevel = map (light_level, minLight, maxLight, 80, 100);
       
       // minLight za 0%
       //maxlight za 100%
       Serial.print ("adjustedLightLevel: ");
       Serial.println(adjustedLightLevel);
       delay(100);
       
  }
