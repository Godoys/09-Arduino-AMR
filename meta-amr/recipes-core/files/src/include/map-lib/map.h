#ifndef MAP
#define MAP

/*
 * Struct that represents a point in the map.
 *
 * @param int x x-coordinate of the point.
 * @param int y y-coordinate of the point.
 * @param int v stands for vacancy, 1 for occupied and 0 fir vacant.
*/

struct point
{
    int x;
    int y;
    int v;
};

/* 
 * Populates the map file with point values from (0, 0)
 * to (p->x, p->y);
 *
 * @param void *s stream containing map file.
 * @param void *p point that will be use as end of the map.
*/

int map_populate(void *s, void *p);

/*
 * Creates an obstacle in the map from the point START
 * until the point END.
 *
 * @param void *s stream containing map file.
 * @param void *start beginning of obstacle.
 * @paran void *end end of obstacle.
 *
 * @return 0 in success, -1 otherwise.
*/

int map_obstacle(void *s, void *start, void *end);

/*
 * Inflates the obstacle in the map by a given rate.
 *
 * @param void *s stream containing map file.
 * @param int rate rate to inflate obstacles.
 *
 * @return 0 in success, -1 otherwise.
*/

int map_inflate(void *s, int rate);

/*
 * Creates obstacles around the perimeter of the map.
 *
 * @param void *s stream containing map file.
 *
 * @return 0 in success, -1 otherwise.
*/

int map_enclose(void *s);

#endif
