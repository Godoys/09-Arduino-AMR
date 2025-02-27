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

File MicroSD::open(String filepath){
  
  File file = mSD.open(filepath, O_RDWR);

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
  : mSD(mSD), filepath(filepath) {

    File file = mSD.open(filepath, O_RDWR);

    String line = file.readStringUntil('\n');

    for (int i = 0; i < line.size(); i++){

      if (line[i] == ','){
        nOfClms++;
      }
    }

  }

String myFile::getLine(int line){

  File file = mSD.open(filepath);

  String rst;

  goToLine(line, file);
  rst = file.readStringUntil('\n');

  file.close();

  return rst
}

void myFile::goToLine(int line, File file){
  file.seek(line * getNumberOfClms());
}






