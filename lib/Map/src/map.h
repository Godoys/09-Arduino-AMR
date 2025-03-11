#pragma once
#include <Arduino.h>
#include "mySD.h"
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
      int ocp;
    } p

    public:

    Point(int x, int y, int ocp);

    int getX();

    int getY();

    int getOcp();
}

class Map : public myFile {

    /*
     * A Map is a reference to a map.csv file that consists of an 
     * 2D array of(X, Y, Occupancy) values.
    */

    public:

    Map(SdFile f, const char *name);

    Map(void);

    void genBoarders();

    void genObstacles(Point start, Point end);

    void inflateLines();

    private:

    void changeRowOcp(int row);

    void changeClmOcp(int clm);
};

