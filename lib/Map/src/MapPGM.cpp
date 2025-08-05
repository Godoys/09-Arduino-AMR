#include "../include/MapPGM.h"
#include <fstream>
#include <iostream>

//------------------------------------------
//           Map Public Methods
//------------------------------------------

MapPGM::MapPGM(string fileName, int nOfRows, int nOfClms, int maxVal) {

    // Creates a fstream object to create new PGM file.
    fstream mapFile;

    // Creates the "filename" file.
    mapFile.open(fileName, ios::in | ios::out | ios::trunc);

    if (!mapFile.is_open()) {
        std::cout << "[!] Error opening file " << fileName << std::endl;
    } else {
        // Adding PMG configuration.
        mapFile << "P5" << endl;
        mapFile << "# Created by Godoy." << endl;
        mapFile << nOfClms << " " << nOfRows << endl;
        mapFile << maxVal << endl;

        // Closing file.
        mapFile.close();
    }
}

fstream MapPGM::open() {

    // Creates a fstream object to open PGM file.
    fstream file;

    // Opens PGM file.
    file.open(this->fileName, ios::in | ios::out);

    // Returns opened file object.
    return file;
}

void MapPGM::close(fstream file) {
    try {
        // Closes file.
        file.close();

        std::cout << "[!] File closed." << std::endl;
    } catch (Exception &e) {
        std::cout << "[!] Error: " << e.what() << std::endl;
    }
}


