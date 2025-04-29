#include <SD.h>
#include <stdio.h>
#include <string.h>

//------------------------------------------
//               Point Class
//------------------------------------------

class Point {

  // A Point is a reference to the (X, Y, OCP) values stored in a Map file.

  struct pointStruct {
    int x;
    int y;
    int ocp;
  };

  pointStruct p;

public:
  Point(int x, int y, int ocp);

  //------------------------------------------
  //     pointStruct Getters and Setters
  //------------------------------------------

  int getX();

  void setX(int n);

  int getY();

  void setY(int n);

  int getOcp();

  void setOcp(int n);
};

//------------------------------------------
//                Map Class
//------------------------------------------

class Map {

  // A Map is a reference to a map.csv file that contains Point values.

  char *filename;
  int nOfClms;
  int nOfRows;

public:
  Map(char *filename);

private:
  // Method to return characters until it finds the terminator character

  char *readCharsUntil(char terminator, File f);

  // Method to go to a specifc row in file.

  void goToRow(int row, File f);

  // Method to go to a specifc column in file.

  void goToClm(int clm, File f);

  // Method to to a specifc element in file.

  void goToElement(int row, int clm, File f);

  // Method to get a element in a specifc position and return it as a Point.

  Point getElement(int row, int clm, File f);

  // Method to generate a point object and return it.

  Point genPoint(int x, int y, int ocp);
};
