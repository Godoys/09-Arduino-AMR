#include "map.h"

/*
 *===================
 * Point Definitions
 *===================
*/

Point::Point(int x, int y, bool ocp)
  : p{x, y, ocp} {}

/*
 * =================
 *  Map Definitions
 * =================
*/

Map::Map(MicroSD mSD, myFile file, int rows, int clms)
  : mSD(mSD), file(file), rows(rows), clms(clms) {}

void Map::genBoarders(){
  
}

void Map::inflateBoarders(int rate){

}

void Map::genObstacle(Point start, Point end){

}

void Map::inflateObstacles(int rate){
  
}










