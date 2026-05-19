#ifndef MAP
#define MAP

struct point
{
    int x;
    int y;
    bool empty;
}

// TODO: Write comments explaining functions.

int map_populate(void *c, point *p);

int map_obstacle(void *c, point *start, point *end);

int map_inflate(void *c, int rate);

// Create obstacles int the perimeter of the map

int map_enclose(void *c);

#endif
