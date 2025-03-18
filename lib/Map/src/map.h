#pragma once
#include <Arduino.h>
#include <SD.h>

class mySD : public SDClass {

  /*
  * mySD exists because I need to SD.open(...) to return a Map object
  * instead of a File object.
  */

  public:

    /*
     * Just a simple implementation of the SD.open(...), but it returns a Map object.
    */

    Map open(const char *filename, uint8_t mode = FILE_READ);

    Map open(const String &filename, uint8_t mode = FILE_READ);

}

class Map : public File {

  /*
  * A Map is a reference to a map.csv file that consists of an 
  * 2D array of(X, Y, Occupancy) values.
  *
  * Map inherents File class from <SD.h> library. 
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

