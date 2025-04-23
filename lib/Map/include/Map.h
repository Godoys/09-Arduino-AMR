#include <SD.h>

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
};
