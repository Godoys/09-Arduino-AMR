#pragma once
#include <Arduino.h>
#include <SD.h>

class Map {

  /*
  * A Map is a reference to a map.csv file that consists of an 
  * 2D array of(X, Y, Occupancy) values.
  *
  * Map inherents File class from <SD.h> library. 
  */

  String filename;
  int nOfClms;
  int nOfRows;
  int nOfCharsOnRow;

  public:

    Map(String filename);

    void open(); // Opens the SD.open(filename, ...)

    void genBoarders(); // Changes the OCP of the first and last row and colum

    void genObstacles(int x1, int y1, int x2, int y2); // Changes the OCP of the line between (x1, y1) and (x2,y2)

    void inflateLines(int rate);

  private:

    void goToLine(int line, File f); // Goes to a specific LINE position with f.seek()

    void goToClm(int clm, int row, File f) // Goes to a specifc CLM position with f.seek()

    void changeOcp(char e, File f); // Flips Ocp 0 to 1 and 1 to 0;

    void changeRowOcp(int row); // Flips a hole row OCP

    void changeClmOcp(int clm); // Flips a hole column OCP

};

