#pragma once
#include <Arduino.h>
#include "microsd.h"
#include <string>
  

class Map {

    /*
     * A Map is a reference to a map.csv file that consists of an 
     * 2D array of(X, Y, Occupancy) values.
     *
     * MSD  --> Represents the MicroSD being used.
     * FILEPATH --> Repreesnts the file path to map.csv.
    */

    MicroSD mSD;
    string filepath;
    int rows;
    int clms;


    public:

    /*
     * A Map constructor will receive a PIN for the initialization of the MicroSD and
     * an FILEPATH for the .csv file that will be used as a map.
     *
     * The constructor will collect the quantity of ROWS and CLMS of the file.
    */

    Map(int pin, string filepath, int rows, int clms);

    void genBoarders();

    void genObstacle();
};

