#include "../include/Map.h"

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
