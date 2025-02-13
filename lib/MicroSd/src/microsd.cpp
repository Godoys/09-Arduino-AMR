#include "microsd.h"

/*
 *=====================
 * MicroSD Definitions
 *=====================
*/

MicroSD::MicroSD(int pin){

  if(!SD.begin(pin)){
    Serial.println("SD Initialization failed");
  }
}
