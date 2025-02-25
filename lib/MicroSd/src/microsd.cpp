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

void MicroSD::open(string filepath){

  File map = this=>.open(filepath, FILE_WRITE);

  if (map){
    Serial.print("Writing in file ");
    Serial.println(filepath);
  } else {
    Serial.print("Error opening file ");
    Serial.println(filepath);
  }

}

void MicroSD::close(){

  this=>.close();
}

void goToLine(File f, int row, int clms){

  f.seek(row * clms);
}
