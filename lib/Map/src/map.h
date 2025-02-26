#pragma once
#include <Arduino.h>
#include "microsd.h"
#include <string>

class Point {

    /* 
     * A Point is a struct composed of the following elements:
     *  - X   --> Represents the x-coordinate.
     *  - Y   --> Represents the y-coordinate.
     *  - OCP --> Represents the occupancy of the point (true --> occupied, false --> empty).
    */

    struct {
      int x;
      int y;
      bool ocp;
    } p

    public:

    Point(int x, int y, bool ocp);
}

class Map {

    /*
     * A Map is a reference to a map.csv file that consists of an 
     * 2D array of(X, Y, Occupancy) values.
     *
     * MSD  --> Represents the MicroSD being used.
     * FILE --> Repreesnts the file that is assigned as map.csv
     * ROWS --> Represents the number of rows in the map.csv file.
     * CLMS --> Represents the numver of colums in the map.csv file.
    */

    myFile file;

    public:

    /*
     * A Map constructor will receive a PIN for the initialization of the MicroSD and
     * an FILEPATH for the .csv file that will be used as a map.
     *
     * The constructor will also receive the quantity of ROWS and CLMS of the file.
    */

    Map(myFile file);

    /*
     * Generate boarders to the FILE. 
     *
     * Boarders are located in the first row and column and last row and column.
    */

    void genBoarders();

    /*
     * Inflate the boarder by a provided RATE.
    */

    void inflateBoarders(int rate);

    /*
     * Generate obstacles lines based on the START and END points given.
    */

    void genObstacle(Point start, Point end);

    /*
     * Inflate the obstacles by a provided RATE.
    */

    void inflateObstacles(int rate);
};

