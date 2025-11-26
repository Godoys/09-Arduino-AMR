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
    char *buf; /* Dynamically sized buffer for data */
    size_t allocated;  /* Size of buf */
    size_t endpos;     /* Number of points in buf */
    off_t offset;      /* Current file offset in buf */
};

ssize_t map_write(void *c, const char *buf, size_t size) {
    char *new_buff;
    struct map_cookie *cookie = c;

    while (size + cookie->offset > cookie->allocated) {
        new_buff = realloc(cookie->buf, cookie->allocated + (size + cookie->offset - cookie->allocated));

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

FILE *map_open(char *file_path, char *mode) {
    FILE *map_file;
    struct map_cookie cookie;
    FILE *stream;

    char id_byte[8] = { 0x4D, 0x41, 0x50, 0x20, 0x46, 0x49, 0x4C, 0x45 };
    char offset[4]  = { 0x00, 0x00, 0x00, 0x15 };

    cookie_io_functions_t map_func = {
        .read  = map_read,
        .write = map_write,
        .seek  = map_seek,
        .close = map_close
    };

    if (access(file_path, F_OK) != 1) {

        /* Checks identification byte */

        map_file = fopen(file_path, mode);

        char file_id_byte[8];
        size_t bytes_read = fread(&file_id_byte, 8, 1, map_file);

        if (bytes_read < 8) {
            return -1;
        }

        for (int i = 0; i < 8; i++) {
            if (id_byte[i] != file_id_byte[i]) {
                return -1;
            }
        }

        /* Set up the cookie before calling fopencookie() */

        cookie.map = map_file;
        cookie.buf = malloc(sizeof(map_file));

        if (cookie.buf == NULL) {
            return -1;
        }

        cookie.allocated = sizeof(map_file);

        bytes_read = fread(&cookie.offset, 4, 1, map_file);

        if (bytes_read < 4) {
            return -1;
        }

        cookie.endpos = 0;

        stream = fopencookie(&cookie, mode, map_func);

        if (stream == NULL) {
            return -1;
        }
    } else {

        map_file = fopen(file_path, "wb");

        /* Adds identification byte to file */

        size_t bytes_wrote = fwrite(&id_byte, 8, 1, map_file);

        if (bytes_wrote < 8) {
            return -1;
        }

        /* Adds the offset to the file */

        bytes_wrote = fwrite(&offset, 4, 1, map_file);

        if (bytes_wrote < 4) {
            return -1;
        }

        /* Adds information about map */

        // TODO: Implement code that writes information about the map
        // file in 8 bytes
        
        /* Populate the file with points */

        // TODO: Implement code that populates map file.
        
        /* Set up the cookie before calling fopencookie() */

        cookie.map = map_file;
        cookie.buf = malloc(sizeof(map_file));

        if (cookie.buf == NULL) {
            return -1;
        }

        cookie.allocated = sizeof(map_file);
        cookie.offset = 21;
        cookie.endpos = 0;

        stream = fopencookie(&cookie, mode, map_func);

        if (stream == NULL) {
            return -1;
        }

    }
    
    return stream;
}
