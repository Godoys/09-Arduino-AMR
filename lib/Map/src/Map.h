#pragma once

#include <SD.h>

class Point {

  // A Point is a reference to the (X, Y, OCP) value stores in a Map file. It
  // will be used as a way to simplify the manipulaton of data inside the Map
  // file.

  struct pointStruct {
    int x;
    int y;
    int ocp;
  };

  pointStruct p;

public:
  Point(int x, int y, int ocp);

  int getX();

  int getY();

  int getOcp();

  void setOcp(int ocp);
};

class Map {

  // A Map is a reference to a map.txt file that consists of an
  // 2D array of (X, Y, OCP) values. (OCP means occupancy)

  char *filename;
  int nOfClms;
  int nOfRows;

public:
  Map(char
          *filename); // Class Constructor, generates nOfClms and nOfRows values

  File open(); // Runs SD.open(filename, O_RDWR) and returns a File object

  void genBoarders(); // Changes the OCP of the first and last rows and columns

  void genObstacles(int x1, int y1, int x2,
                    int y2); // Changes the OCP of the line
                             // between (x1, y1) and (x2, y2)

  void inflateLines(int rate); // Inflate size of lines by RATE

private:
  void goToInitialPos(File f); // Goes to file initial position with f.seek(0);

  void goToRow(int row, File f); // Goes to a specific ROW position

  void goToClm(int clm, File f); // Goes to a specific CLM position

  void goToElement(int clm, int row,
                   File f); // Goes to a specific element position

  Point getElement(int clm, int row, File f); // Gets a specific element

  Point genPoint(char s[]); // Generates a point from "X;Y;OCP" char array

  Point *getRowPoints(int row, File f); // Return an array of Points

  void chanceOcp(Point p, int ocp); // Changes a Point OCP

  void changeRowOcp(int row, int ocp, File f); // Changes a row of Points OCP

  void changeClmOcp(int clm, int ocp, File f); // Changes a clm of Points OCP
};
