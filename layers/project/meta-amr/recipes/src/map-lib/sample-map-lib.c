#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

struct map_cookie {
  FILE *map;
  int *buf;         /* Dynamically sized buffer for data */
  size_t allocated; /* Size of buf */
  size_t endpos;    /* Number of points in buf */
  off_t offset;     /* Current file offset in buf */
};

struct point {
  int x; /* X coordinate of the point */
  int y; /* Y coordinate of the point */
};
