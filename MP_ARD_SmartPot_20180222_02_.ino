/*
 * name Mihaela Petkova
 * name project SmartPot
 * date 22.02.2018
 * 
This example shows how to connect to Cayenne using an Ethernet W5100 shield and send/receive sample data.

The CayenneMQTT Library is required to run this sketch. If you have not already done so you can install it from the Arduino IDE Library Manager.

Steps:
1. Set the Cayenne authentication info to match the authentication info from the Dashboard.
2. Compile and upload the sketch.
3. A temporary widget will be automatically generated in the Cayenne Dashboard. To make the widget permanent click the plus sign on the widget.
*/

/** @see https://www.facebook.com/photo.php?fbid=10215060465886540&set=gm.1890454251246596&type=3&ifg=1 */
/** @brief that link */

/** @bief the define the Cayenne lib for _DEBUG*/
#define CAYENNE_PRINT Serial 
#include <CayenneMQTTEthernet.h>

/** @brief the analog pin for Soil Moisture and Humidity Sensor on the Arduino.*/
#define PIN_SMHS A0

/** @brief the */

/** @brief pump for watering (12V)*/
#define PIN_PUMP A2

/** @brief photo resistor*/
#define PIN_PHOTO_R 5.0F

/** @brief change the define*/
/**@brief the Sensor Percent Value */
volatile uint8_t SenPerVal_g;

/** @brief the connection for Cayenne. */
/** @see https://cayenne.mydevices.com/ */
char username[] = "username";
char password[] = "password";
char clientID[] = "clientid";

/** @brief math function .*/
/** @return uint8_t @brief on the analog pin on the Arduino.*/
uint8_t sensor_read()
{
  /** @brief variables .*/ 
  static int TmplValueL;
  TmplValueL=0;
  TmplValueL = analogRead (TmplValueL);
  TmplValueL = map(TmplValueL, 400, 1023, 100, 0);
  TmplValueL = constrain (TmplValueL, 400, 1023);
  return(uint8_t)(255&TmplValueL);
  
}

void setup() 
{
  Serial.begin(9600);
  /** @brief the begin Cayenne .*/
  Cayenne.begin(username, password, clientID);
    /*Setting up the Soil Humidity Sensor Pin to receive data */
  pinMode(PIN_SMHS, INPUT);
  /*Setting up the Photo Resistor Pin to receive data*/
  pinMode(PIN_PHOTO_R, INPUT);
}

void loop() 
{
  /** @brief the loop func Cayenne .*/
  Cayenne.loop();
}

// Default function for sending sensor data at intervals to Cayenne.
// You can also use functions for specific channels, e.g CAYENNE_OUT(1) for sending channel 1 data.
CAYENNE_OUT_DEFAULT()
{  
  uint8_t sensor_read();

  // Write data to Cayenne here. This example just sends the current uptime in milliseconds on virtual channel 0.
  // Cayenne.virtualWrite(0,TmplValueL);
  // Some examples of other functions you can use to send data.
  //Cayenne.celsiusWrite(1, 22.0);
  //Cayenne.luxWrite(2, 700);
  //Cayenne.virtualWrite(3, 50, TYPE_PROXIMITY, UNIT_CENTIMETER);
}

/** @brief Default function for processing actuator commands from the Cayenne Dashboard.*/
/** @brief You can also use functions for specific channels, e.g CAYENNE_IN(1) for channel 1 commands.*/
CAYENNE_IN_DEFAULT()
{
  CAYENNE_LOG("Channel %u, value %s", request.channel, getValue.asString());
  /** @Process message here. If there is an error set an error message using getValue.setError(), e.g getValue.setError("Error message");*/
}
