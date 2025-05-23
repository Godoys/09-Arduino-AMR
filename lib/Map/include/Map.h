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
  int nMaxOfPointDigits = 26;

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

  // Method to go to position 0 of file.

  void goToInitialPos(File f);

  // Method to get all the points of a row and return it as a Point *array.

  Point *getRowPoints(int row, File f);

  // Method to get all the points of a column and return it as a Point *array.

  Point *getClmPoints(int clm, File f);

  // Method to change a Point Ocp value and return a Point with the value
  // changed.

  Point changePointOcp(Point p, int ocp);

  // Method to replace changed ocp on file.

  void writePoint(Point p, File f);

  // Method to convert a Point into a X;Y;OCP pointer to char array;

  char *pointToChar(Point p);
};
