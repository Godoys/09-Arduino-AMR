#include "../include/MapPGM.h"
#include <fstream>

//------------------------------------------
//           Map Public Methods
//------------------------------------------

MapPGM::MapPGM(string fileName, int nOfRows, int nOfClms, int maxVal) {

    // Creates a fstream object to create new PGM file.
    fstream mapFile;

    // Creates the "filename" file.
    mapFile.open(fileName, ios::in | ios::out | ios::trunc);

    // Adding PMG configuration.
    mapFile << "P5" << endl;
    mapFile << "# Created by Godoy." << endl;
    mapFile << nOfClms << " " << nOfRows << endl;
    mapFile << maxVal << endl;

    // Closing file.
    mapFile.close();
}
