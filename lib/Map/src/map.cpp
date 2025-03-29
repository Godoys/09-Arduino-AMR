#include "map.h"

Map::Map(String filename)
  : filename(filename) {

    File f = SD.open(filename, O_RDWR);

    String s = f.readStringUntil('\n');

    for(char c : s) {
      
      nOfCharOnRow++;

      if (c == ',') {
        nOfClms++;
      }

      if (c == '\n') {
        nOfRows++
      }
    }

    nOfCharOnRow += 1; // Adds one to go from the pos of '\n' to the beggining of
                       // the next line

    nOfClm += 1; // Row has 2 ',' + 1 column
  };

File Map::open(){
  return SD.open(filename, O_RDWR);
}

void Map::genBoarders(){
  changeRowOcp(0, '1');
  changeRowOcp(nOfRows - 1, '1');
  changeClmOcp(0, '1');
  changeClmOcp(nOfClm - 1, '1');
}

void genObstacles(int x1, int y1, int x2, int y2){

  File f = SD.open(filename, O_RDWR);

  int max_x = nOfRows;
  int max_y = nOfClms;

  if (x1 > max_x || x2 > max_x){
    Serial.print("Error! X coordinate do not exist in this MAP");
  } else if (y1 > max_y || y2 > max_y){
    Serial.print("Error! Y coordinate do not exist in this MAP");
  }

  int slope (y2 - y1)/(x2 - x1);
  int b = y1 - (slope * x1);

  for (int i = x1; i <= x2; i++){
    
    int y = (slope * i) + b;

    goToElement(i, y, f);

    changeOcp('1', f);
  }
}

void Map::goToLine(int line, File f){
  f.seek(line);
}

void Map::goToElement(int clm, int row, File f){
  f.seek((row * nOfCharOnRow) + (clm * 8) + 5);
}

void Map::changeOcp(char ocp, File f){
  if (ocp == '0') {
    f.print('0');
  } else {
    f.print('1');
  }
}

void changeRowOcp(int row, char ocp){

  File f = SD.open(filename, O_RDWR);

  goToLine((row * nOfCharOnRow), f);

  for (int i = 0; i < nOfClms; i++) {
                                         
    goToElement(i, row, f);

    changeOcp(ocp, f);
  }

  f.close();
}

void changeClmOcp(int clm, char ocp){

  File f = SD.open(filename, O_RDWR);

  for (int i = 0; i < nOfRows; i++) {
    
    goToElement(clm, i, f);
    changeOcp(ocp, f);
  }

  f.close();
}





