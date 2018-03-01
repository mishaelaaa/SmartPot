#include <PID_v1.h>
//Define Variables we'll be connecting to double Setpoint, Input, Output;
//Define the aggressive and conservative Tuning Parameters

double aggKp=4, aggKi=0.2, aggKd=1;
double consKp=1, consKi=0.05, consKd=0.25;
//Specify the links and initial tuning parameters

PID myPID(&Input, &Output, &Setpoint, consKp, consKi, consKd, DIRECT);

void setup()
  {
  Serial.begin(115200);
  //initialize the variables we're linked to
  
  Input = map(analogRead(0), 0, 1023, 255, 0);
  Setpoint = 650;
  myPID.SetOutputLimits(0, 255);
  //turn the PID on
  
  myPID.SetMode(AUTOMATIC);
}
void loop()
  {
  int sensorValue = analogRead(0);
  Input = map(analogRead(0), 0, 1023, 255, 0);
  double gap = abs(Setpoint-Input); //distance away from setpoint
  if(gap<10)
  { 
    //we're close to setpoint, use conservative tuning parameters
   myPID.SetTunings(consKp, consKi, consKd);
  }
    else
    {
      //we're far from setpoint, use aggressive tuning parameters
      myPID.SetTunings(aggKp, aggKi, aggKd);
    }
  myPID.Compute();
  analogWrite(3,Output);
  Serial.println(sensorValue);
 }
