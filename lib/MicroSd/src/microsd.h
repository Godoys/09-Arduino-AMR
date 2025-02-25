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
   *
  */

  public:

  MicroSD(int pin);

  void open(string filepath);

  void close();

  void goToLine(int row, int clms);
}
