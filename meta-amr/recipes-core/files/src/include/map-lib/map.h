#ifndef MAP
#define MAP

/*
 * Struct that represents a point in the map.
 *
 * @param int x x-coordinate of the point.
 * @param int y y-coordinate of the point.
 * @param int empty 1 for not empty and 0 for empty.
*/

struct point
{
    int x;
    int y;
    int empty;
};

/* 
 * Populates the map file with point values from (0, 0)
 * to (p->x, p->y);
 *
 * @param void *c structure containing map reference.
 * @param void *p point that will be use as end of the map.
 * 
*/

int map_populate(void *c, void *p);

/*
 * Creates an obstacle in the map from the point START
 * until the point END.
 *
 * @param void *c structure containing map reference.
 * @param void *start beginning of obstacle.
 * @paran void *end end of obstacle.
 *
 * @return 0 in success, -1 otherwise.
*/

int map_obstacle(void *c, void *start, void *end);

/*
 * Inflates the obstacle in the map by a given rate.
 *
 * @param void *c structure containing map reference.
 * @param int rate rate to inflate obstacles.
 *
 * @return 0 in success, -1 otherwise.
*/

int map_inflate(void *c, int rate);

/*
 * Creates obstacles around the perimeter of the map.
 *
 * @param void *c structure containing map reference.
 *
 * @return 0 in success, -1 otherwise.
*/

int map_enclose(void *c);

#endif
