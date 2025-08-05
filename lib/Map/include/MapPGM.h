#include <string>

class MapPGM {

    // A Map is an interface to a Portable Grey Map (PGM) file. It defines commands such as
    // create, delete, read, write, etc.

    string fileName;
    int nOfRows;
    int nOfClms;
    int maxVal;

public:

    // Creates a new "fileName.pmg" file with rows = nOfRows, columns = nOfClms, and max val = maxVal or 1.
    MapPGM(string fileName, int nOfRows, int nOfClms, int maxVal = 1);

    // Opens the fileName file.
    fstream open();

    // Closes the fileName file/
    void close(fstream file);
};