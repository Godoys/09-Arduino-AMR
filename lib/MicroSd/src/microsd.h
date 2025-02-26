#pragma once
#include <Arduino.h>
#include <SD.h>

class MicroSD {

  /*
   * A MicroSD object is a representation of a physical MicroSD.
   *
   * The purpose of this class is to create an easy and usefull interface between the code
   * and the MicroSD.
   *
   * Pin in the constructors rerpesents the communication pin in the Arduino Board.
  */

  SD mSD;

  public:

  MicroSD(int pin);

  /*
   * Opens a FILEPATH in MODE from MSD.
  */

  File open(string filepath, string mode);
}

class myFile {

  /*
   * A myFile object is a representation of a file inside a MicroSD.
   *
   * The purpose of this class is to create new methods for the File class
   * already created by the <SD.h> library.
   *
   * MSD     --> Represents a real MicroSD.
   * FILE    --> Represents a file inside MSD. It extends the useful methods
   *             of <SD.h> File class.
   * NOFCLMS --> Represents the number of columns in the given file.
  */

  MicroSD mSD;
  File file;
  int nOfClms;

  public:

  myFile(MicroSD mSD, File file);

  /*
   * Closes FILE.
  */

  void close();

  /*
   * Returns the full line as a STRING.
  */

  String getLine(int line);

  private:

  /*
   * Get the number of columns based on the number of rows, since the map will
   * always be a square.
  */
  
  int getNumberOfClms();

  /*
   * Uses file.seek() to go to a specific line position.
  */

  void goToLine(int line);
}





