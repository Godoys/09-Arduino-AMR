#include "microsd.h"

/*
 *=====================
 * MicroSD Definitions
 *=====================
*/

MicroSD::MicroSD(int pin){

  if(!mSD.begin(pin)){
    Serial.println("SD Initialization Failed");
  } else {
    Serial.println("SD Initialization Succeded")
  }
}

File MicroSD::open(String filepath, String mode){
  
  File file = mSD.open(filepath, mode);

  if (file){
    Serial.print("Successfully Opened: ");
    Serial.println(filepath);
  } else {
    Serial.print("Error Opening: ");
    Serial.print(filepath);
  }

  return file;
}

/*
 *====================
 * myFile Definitions
 *====================
*/

myFile::myFile(MicroSD mSD)
  : mSD(mSD) {}

void myFile::close(){
  file.close();
}

String myFile::getLine(int line){

  String rst;

  goToLine(line);
  rst = file.readStringUntil('\n');

  return rst
}

int myFile::getNumberOfClms(){
  
  int counter = 0;

  while (file.avaiable()){

    if (file.peek() ==  '\n'){
      
      counter++;
      file.read();
    } else {

      file.read();
    }
  }

  return counter;
}

void myFile::goToLine(int line){
  file.seek(line * getNumberOfClms());
}






