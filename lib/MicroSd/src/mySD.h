#pragma once
#include <Arduino.h>
#include <SD.h>

class mySD : public SDClass {

  /*
   * A mySD object is a representation of a physical MicroSD. It derives from the <SD.h>
   * library SDClass.
   *
   * The purpose of this class is alter the OPEN method defined in the SDClass to return
   * the myFile object.
   *
   * Pin in the constructors rerpesents the communication pin in the Arduino Board.
  */

  public:

    /*
     * Open the specified file/directory with the supplied mode (e.g. read or write).
     * Returns a mapFile object for interacting with the file.
    */

    mapFile open(const char *filename, uint8_t mode = FILE_READ);

    mapFile open(const String &filename, uint8_t mode = FILE_READ){
      return open(filename.c_str(), mode);
    }

}

class myFile : public File {

  /*
   * A myFile object is a representation of a file inside a MicroSD. It derives from the
   * <SD.h> library File.
   *
   * The purpose of this class is to create new methods for the File class
   * already created by the <SD.h> library.
  */

  public:

    myFile(SdFile f, const char *name);

    myFile(void);

    String getRow(int row);

    String getClm(int clm);

    String getElement(int row, int clm)

  private:

    void goToRow(int row);

    void goToClm(int clm);

    void goToElement(int row, int clm);

}  
