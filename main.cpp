#include "lib/Map/include/MapPGM.h"
#include <string>

// Functions and methods to be run once before program starts.
void setup() {

    string fileName = "Test.pgm";

    MapPGM map = new MapPGM(fileName, 5, 5, 1);
}

// Functions and method to be run continuously after program starts.
void loop() {}