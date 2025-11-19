#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define INIT_BUF_SIZE 4

struct memfile_cookie {
  char *buf;        /* Dynamically sized buffer for data */
  size_t allocated; /* Size of buf */
  size_t endpos;    /* Number of characters in buf */
  off_t offset;     /* Current file offset in buf */
};

static ssize_t memfile_write(void *c, const char *buf, size_t size) {
  char *new_buff;
  struct memfile_cookie *cookie = c;

  /* Buffer too small? Keep doubling size until big enough */

  while (size + cookie->offset > cookie->allocated) {
    new_buff = realloc(cookie->buf, cookie->allocated * 2);

    if (new_buff == NULL)
      return -1;

    cookie->allocated *= 2;
    cookie->buf = new_buff;
  }

  memcpy(cookie->buf + cookie->offset, buf, size);

  cookie->offset += size;

  if (cookie->offset > cookie->endpos)
    cookie->endpos = cookie->offset;

  return size;
}

static ssize_t memfile_read(void *c, char *buf, size_t size) {
  ssize_t xbytes;
  struct memfile_cookie *cookie = c;

  /* Fetch minimum of bytes requested and bytes available */

  xbytes = size;

  if (cookie->offset + size > cookie->endpos)
    xbytes = cookie->endpos - cookie->offset;
  if (xbytes < 0)
    xbytes = 0; /* offset may be past endpos */

  memcpy(buf, cookie->buf + cookie->offset, xbytes);

  cookie->offset += xbytes;
  return xbytes;
}

static int memfile_seek(void *c, off_t *offset, int whence) {
  off_t new_offset;
  struct memfile_cookie *cookie = c;

  if (whence == SEEK_SET) {
    new_offset = *offset;
  } else if (whence == SEEK_END) {
    new_offset = cookie->endpos + *offset;
  } else if (whence == SEEK_CUR) {
    new_offset = cookie->offset + *offset;
  } else {
    return -1;
  }

  if (new_offset < 0)
    return -1;

  cookie->offset = new_offset;
  *offset = new_offset;
  return 0;
}
