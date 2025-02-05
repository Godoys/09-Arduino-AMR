#pragma once
#include <Arduino.h>


class Point {

    /*
     * A point is represented by a STRUCT with three components:
     *  - x, which represents the x coordinate
     *  - y, which represents the y coordinate
     *  - ocp, which represents the occupancy (1: occupied, 0: free)
    */

    struct point {
        int x;
        int y;
        int ocp;
      } p;

      public:

      Point(int x, int y, int ocp);

      Point();

      int getX();

      int getY();

      int getOcp();

};

class Map {

    /*
     * A Map is a collection of Point Objects distributed in a 2D array:
     *
     * For example:
     *  - Map m1 = [[p1, p2], [p3, p4]];
     *
    */

    Point** map;
    int rows;
    int clms;

    public:

    /*
     * A Map constructor will receive an START and END point.
     *
     * The constructor will generate through loops the Map (which consists of an 2D array)
    */

    Map(Point start, Point end);

    void printMap();
};

