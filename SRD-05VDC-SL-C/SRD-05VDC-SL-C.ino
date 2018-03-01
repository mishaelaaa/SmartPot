void setup() {
 // initialize digital pin 3 as an output.
 pinMode(7, OUTPUT); 
}
//The main loop will continue to run until the arduino loses power
void loop() {
 digitalWrite(7, LOW); // turn the relay off to start
 delay(3000); // wait for 3 seconds
 digitalWrite(7, HIGH); // turn the relay on to turn on the light
 delay(3000); // wait for 3 seconds 
}
