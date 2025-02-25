#include "map.h"


/*
 * =================
 *  Map Definitions
 * =================
*/

Map::Map(int pin, string filepath, int rows, int clms)
  : mSD(pin), filepath(filepath), rows(rows), clms(clms) {}

void Map::genBoarders(){
  
  File map = mSD.open(filepath);


}

void Map::genObstacle(){
}










