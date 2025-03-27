#include "map.h"

Map::Map(String filename)
  : filename(filename) {

    File f = SD.open(filename, O_RDWR);

    String s = f.readStringUntil('\n');

    for(char c : s) {
      
      nOfCharOnRow++;

      if (c == ',') {
        nOfClm++;
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

void Map::goToLine(int line, File f){
  f.seek(line);
}

void Map::goToClm(int clm, int row, File f){
  f.seek((row * 25) + (clm * 8) + 5);
}

void Map::changeOcp(char e, File f){
  if (e == '0') {
    f.print('1');
  } else {
    f.print('0');
  }
}

void changeRowOcp(int row){

  File f = SD.open(filename, O_RDWR);

  goToLine((row * nOfCharOnRow), f);

  for (int i = 0; i < nOfClm; i++) {
                                         
    goToClm(i, row, f);

    changeOcp(f.peek(), f);
  }

  f.close();
}

void changeClmOcp(int clm){

  File f = SD.open(filename, O_RDWR);

  for (int i = 0; i < nOfRows; i++) {
    
    goToClm(clm, i, f);
    changeOcp(f.peek(), f);
  }

  f.close();
}





