#include <string.h>
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

struct Point {
  int x; /* X coordinate of the point */
  int y; /* Y coordinate of the point */
};

struct map_cookie {
  FILE *map;
  struct Point *buf; /* Dynamically sized buffer for data */
  size_t allocated;  /* Size of buf */
  size_t endpos;     /* Number of points in buf */
  off_t offset;      /* Current file offset in buf */
};

ssize_t map_read(void *c, char *buf, size_t size) {
  ssize_t nbytes;
  struct map_cookie *cookie = c;

  /* Fetch minimum of bytes requested and bytes availabe */

  nbytes = size;

  if (cookie->offset + size > cookie->endpos) {
    nbytes = cookie->endpos - cookie->offset;
  }
  if (nbytes < 0) {
    nbytes = 0; /* offset may be past endpos */
  }

  memcpy(buf, cookie->buf + cookie->offset, nbytes);

  cookie->offset += nbytes;
  return nbytes;
}

int map_seek(void *c, off_t *offset, int whence) {
  off_t new_offset;
  struct map_cookie *cookie = c;

  switch (whence) {
  case SEEK_SET:
    new_offset = *offset;
    break;
  case SEEK_END:
    new_offset = cookie->endpos + *offset;
    break;
  case SEEK_CUR:
    new_offset = cookie->offset + *offset;
  default:
    return -1;
  }

  if (new_offset < 0) {
    return -1;
  }

  cookie->offset = new_offset;
  *offset = new_offset;
  return 0;
}
