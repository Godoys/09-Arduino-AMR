#include "Map.h"
#include "utility/SdFat.h"

Map::Map(char *filename) : filename(filename) {

  File f = SD.open(filename, O_RDWR);

  while (f.available()) {

    char c = f.read();

    if (c == ',' && nOfRows < 1) {
      nOfClms++;
    }

    if (c == '\n') {
      nOfRows++;
    }
  }

  nOfClms += 1; // Row has 2 ',' + 1 column
}

/*
 * =====================================================================================
 *                               Public Methods Definitions
 * =====================================================================================
 */

/*
 * ========================================================================================
 *                             Private Methods Definition
 * ========================================================================================
 */

File Map::open() { return SD.open(filename, O_RDWR); }

void Map::goToInitialPos(File f) { f.seek(0); }

void Map::goToRow(int row, File f) {

  int nOfNewLineSymbols = 0;

  while (nOfNewLineSymbols < row) {

    char c = f.read();

    if (c == '\n') {
      nOfNewLineSymbols++;
    }
  }
}

void Map::goToClm(int clm, File f) {

  int pos = f.position();

  if (clm == 0) {
    goToInitialPos(f);
  } else {

    f.seek(pos + 1);

    int nOfParenthesis = 0;

    while (nOfParenthesis < (clm + 1)) {

      char c = f.read();

      if (c == '(') {
        nOfParenthesis++;
      }
    }
  }
}

void Map::goToElement(int clm, int row, File f) {
  goToRow(row, f);
  goToClm(clm, f);
}
