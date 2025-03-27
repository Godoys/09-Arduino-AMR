#include "map.h"

Map::Map(String filename)
  : filename(filename) {

    File f = SD.open(filename, O_RDWR);

    String s = f.readStringUntil('\n');

    for(char c : s) {
      nOfCharOnRow++;
    }

    nOfCharOnRow += 1; // Adds one to go from the pos of '\n' to the beggining of
                       // the next line
  };

File Map::open(){
  return SD.open(filename, O_RDWR);
}

void Map::goToLine(int line, File f){
  f.seek(line);
}

char Map::changeOcp(char e){
  if (e == '0') {
    return '1';
  } else {
    return '0';
  }
}

void changeRowOcp(int row){

  File f = SD.open(filename. O_RDWR);

  goToLine((row * nOfCharOnRow), f);

  String overrideText = f.readStringUntil('\n');

  for (int i = 0; i < overrideText.length(); i++) {

    int nextChangeableEle = 5 + (8 * 1); // Calculates the position of the next OCP
                                         
    if (i == 0) {
      overrideText[5] = changeOcp(overrideText[5]);
    } else {
      overrideText[nextChangeableEle] = changeOcp(overrideText[nextChangeableEle]);
    }
  }

  goToLine(0, f);

  f.println(overrideText);
}





