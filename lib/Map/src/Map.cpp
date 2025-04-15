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
