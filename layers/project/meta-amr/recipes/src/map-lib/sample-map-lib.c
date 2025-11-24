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

ssize_t map_write(void *c, const char *buf, size_t size) {
    char *new_buff;
    struct map_cookie *cookie = c;

    while (size + cookie->offset > cookie->allocated) {
        new_buff = realloc(cookie->buff, cookie->allocated + (size + cookie->offset - cookie->allocated));

        if (new_buff == NULL){
            return -1;
        }

        cookie->allocated += size + cookie->offset - cookie->allocated;
        cookie->buf = new_buff;
    }

    memcpy(cookie->buf + cookie->offset, buf, size);

    cookie->offset += size;

    if (cookie->offset > cookie->endpos) {
        cookie->endpos = cookie->offset;
    }

    return size;
}

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

int map_close(void *c) {
    struct map_cookie *cookie = c;

    /* Writes data in buffer to .map file */

    rewind(cookie->map);
    fwrite(cookie->buf, sizeof(cookie->buf), 1, cookie->map);

    fclose(cookie->map);
    free(cookie->buf);
    cookie->allocated = 0;
    cookie->buf = NULL;

    return 0;
}
