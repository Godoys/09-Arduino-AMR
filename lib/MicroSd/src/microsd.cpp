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
  
  File file;

  if (mode == "FILE_READ"){
    file = mSD.open(filepath, FILE_READ);
  } else if (mode == "FILE_WRITE"){
    file = mSD.open(filepath, FILE_WRITE);
  } else if (mode == "O_RDWR"){
    file = mSD.open(filepaht, O_RDWR);
  }

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

myFile::myFile(MicroSD mSD, String filepath)
  : mSD(mSD), filepath(filepath) {}

String myFile::getLine(int line){

  File file = mSD.open(filepath, "FILE_READ");

  String rst;

  goToLine(line, file);
  rst = file.readStringUntil('\n');

  file.close();

  return rst
}

void myFile::goToLine(int line, File file){
  file.seek(line * getNumberOfClms());
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






