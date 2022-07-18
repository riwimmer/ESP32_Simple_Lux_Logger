#include "SPIFFS.h"
#include <Wire.h>
#include "DFRobot_VEML7700.h" 

//Instantiate sensor object
DFRobot_VEML7700 als; 

// create global variable for sensor data
  float lux; 
  int counter;
  String str;
  static char outstr[7];

void setup() {

   //Set serial debug at 115.2kbaud 
   Serial.begin(115200);

   //Initiate als object
   als.begin();

   // Check if SPIFFS flash mouting is possible, stop here if not
   if(!SPIFFS.begin(true)){
        Serial.println("An Error has occurred while mounting SPIFFS");
        return;
   }
 
    
}
 
void loop() {

  // read sensor data 
  als.getALSLux(lux);

  //convert the float to a string
  //as lux reading can be up over 100k use 6 digit and no decimal point
  //that is accurate enough for this data collect
  dtostrf(lux,6, 0, outstr);


    //--------- Apend sensor reading to file
    File fileToAppend = SPIFFS.open("/sensor.txt", FILE_APPEND);

    //debug
    //Serial.println(str);

    if(!fileToAppend){
        Serial.println(outstr);
        return;
    }

    if(!fileToAppend.println(outstr)){
        Serial.println("File append failed");
    }
    
 
    fileToAppend.close();

    //just wait 30 sec and read again, resulting in 120 data points p. h. or 2880 data points p. d.
    delay(30000);
  
  }
