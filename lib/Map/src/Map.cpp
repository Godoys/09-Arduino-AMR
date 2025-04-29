#include "../include/Map.h"
#include <cstring>

//------------------------------------------
//           Map Public Methods
//------------------------------------------

Map::Map(char *filename) : filename(filename) {

  File f = SD.open(filename, O_RDWR);

  // Buffer to contain line characters.

  char *buffer;

  buffer = readCharsUntil('\n', f);

  // Counts the number of ROWS and the number of COLUMNS in the file.

  for (int i = 0; i < 1024; i++) {

    char c = buffer[i];

    // The number of ',' plus one in a line means the number of columns it has.

    if (c == ',') {
      nOfClms++;
    }
  }

  nOfClms++;

  // Return to first character in file.

  f.seek(0);

  while (f.available()) {

    char c = f.read();

    // The number of '\n' in a file means the number of lines it has.

    if (c == '\n') {
      nOfRows++;
    }
  }
}

//------------------------------------------
//           Map Private Methods
//------------------------------------------

char *Map::readCharsUntil(char terminator, File f) {

  // Buffer for storing line characters.

  char buffer[1024];

  // Variable for loop.

  int i = 0;

  while (f.peek() != terminator) {

    char c = f.read();

    buffer[i] = c;

    i++;
  }

  char *resutl = &buffer[0];

  return resutl;
}

void Map::goToRow(int row, File f) {

  // Number of '\n' counted.

  int nOfNewLine = 0;

  // Goes to a specific row by counting the number of '\n'.

  while (nOfNewLine < row) {

    char c = f.read();

    if (c == '\n') {
      nOfNewLine++;
    }
  }
}

void Map::goToClm(int clm, File f) {

  // Gets the current position in file.

  int pos = f.position();

  if (clm == 0) {

    // Goes to the first character of first line.

    f.seek(pos + 1);

  } else {

    int nOfOpenParenthesis = 0;

    while (nOfOpenParenthesis < (clm + 1)) {

      char c = f.read();

      if (c == '(') {
        nOfOpenParenthesis++;
      }
    }
  }
}

void Map::goToElement(int row, int clm, File f) {
  goToRow(row, f);
  goToClm(clm, f);
}

Point Map::getElement(int row, int clm, File f) {

  // Buffer to store point.

  char *point;

  // Go to point position.

  goToElement(row, clm, f);

  // Populates point buffer with point info.

  point = readCharsUntil(')', f);

  // Variables to construct Point instance.

  int x;
  int y;
  int ocp;

  // Gets each element of (X;Y:OCP) with strtok and convert it to a string using
  // atoi().

  x = atoi(strtok(point, ";"));
  y = atoi(strtok(NULL, ";"));
  ocp = atoi(strtok(NULL, ";"));

  // Returns Point Object using genPoint function().

  return genPoint(x, y, ocp);
}

Point Map::genPoint(int x, int y, int ocp) { return Point(x, y, ocp); }

void Map::goToInitialPos(File f) { f.seek(0); }
