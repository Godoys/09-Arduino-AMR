#include <"map.h">

Map mySD::open(const char *filename, uint8_t mode = FILE_READ){
  
  int pathidx = 0;

  // Do interactive search

  SdFile parentdir = SDClass::getParentDir(filepath, &pathidx);

  filepath += pathidx;

  if (!filepath[0]) {
    return Map(parentdir, "/");
  }

  // Open the file itself
  
  Sdfile file;

  // Failed to open a subdir
  
  if (!parentdir.isOpen()) {
    return Map();
  }

  if (!file.open(parentdir, filepath, mode)) {
    return Map();
  }

  // Close the parent
  
  parentdir.close();

  if ((mode & (O_APPEND | O_WRITE)) == (O_APPEND | O_WRITE)) {
    file.seekSet(file.fileSize());
  }

  return File(file, filepath);
}

Map mySD::open(const String &filename, uint8_t mode = FILE_READ){
  return open(filename.c_str(), mode);
}
