#include <string>

class MapPGM {

    // A Map is an interface to a Portable Grey Map (PGM) file. It defines commands such as
    // create, delete, read, write, etc.

    string fileName;
    int nOfRows;
    int nOfClms;
    int maxVal;

public:

    MapPGM(string fileName, int nOfRows, int nOfClms, int maxVal = 1);

    fstream open();
};