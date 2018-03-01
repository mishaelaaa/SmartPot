/*
 * name Mihaela Petkova
 * name project SmartPot
 * date 22.02.2018
 */

/**@brief the analog pin for Soil Moisture and Humidity Sensor on the Arduino.*/
#define PIN_SMHS A0

#define SENSOR_5.0F
/**@see https://www.facebook.com/groups/1794588907499798/?ref=group_header */
/**@brief the Sensor Percent Value */
volatile uint8_t SenPerVal_g;

/**@brief function for math function .*/
/**@param ................. .*/
/**@return uint8_t @brief on the analog pin on the Arduino.*/
uint8_t sensor_read()
{
  /**@brief variables .*/ 
  static int TmplValueL;
  TmplValueL=0;
  TmplValueL = analogRead (TmplValueL);
  TmplValueL = map(TmplValueL, 400, 1023, 100, 0);
  TmplValueL = constrain (TmplValueL, 400, 1023);
  return(uint8_t)(255&TmplValueL);
  
  /*  1/ четем входа
      2/мащабиране
      3/ограничаваме стойността
      4/return(uint8_t)(255&TmpValuueL);
   */
}

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
