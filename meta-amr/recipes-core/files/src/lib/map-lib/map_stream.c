#define _GNU_SOURCE
#include "map_stream.h"

ssize_t map_write(void *c, const char *buf, size_t size)
{
    struct map_cookie *cookie = c;
    
    if (pwrite(cookie->fd, buf, size, cookie->offset) < 0) {
        perror("[!] Write");
        exit(EXIT_FAILURE);
    }

    cookie->offset = size;

    return size;
}

ssize_t map_read(void *c, char *buf, size_t size)
{
    /*
    ssize_t xbytes;
    struct map_cookie *cookie = c;

    xbytes = size;

    if (cookie->offset + size > cookie->endpos)
        xbytes = cookie->endpos - cookie->offset;
    if (xbytes < 0)
        xbytes = 0;

    memcpy(buf, cookie->buf + cookie->offset, xbytes);

    cookie->offset += xbytes;
    return xbytes;
    */
}

int map_seek(void *c, off_t *offset, int whence)
{
    /*
    off_t new_offset;
    struct map_cookie *cookie = c;

    if (whence == SEEK_SET)
        new_offset = *offset;
    else if (whence == SEEK_END)
        new_offset = cookie->endpos + *offset;
    else if (whence == SEEK_CUR)
        new_offset = cookie->offset + *offset;
    else
        return -1;

    if (new_offset < 0)
        return -1;

    cookie->offset = new_offset;
    *offset = new_offset;
    return 0;
    */
}

int map_close(void *c)
{
    struct map_cookie *cookie = c;

    /* Free cookie pointer */

    free(cookie);

    /* Closes file opened with open() */

    if (close(cookie->fd) < 0) {
        perror("[!] Close");
        exit(EXIT_FAILURE);
    }

    return 0;
}

/* 
 * What this function should do?
 *
 * Open the .map file and read the first X points
 * and store it in the buffer, then perform operations as usual.
 *
 * If user wants to look at points further that are not in the 
 * buffer, we should take another batch of X points and store in the buffer.
 *
*/

FILE *map_open(char *map_path)
{
    cookie_io_functions_t map_func = {
        .read  = map_read,
        .write = map_write,
        .seek  = map_seek,
        .close = map_close
    };

    FILE *stream;
    struct map_cookie *c = malloc(sizeof(*c));

    if (c == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    /* Set up the cookie before calling fopencokkie */

    if (access(map_path, F_OK) == 0) {

        c->fd = open(map_path, O_RDWR);

        if (c->fd == -1) {
            perror("[!] open");
            exit(EXIT_FAILURE);
        }

        if (map_check_signature(c) != 0){
            perror("[!] map_check_signature");
            exit(EXIT_FAILURE);
        }

    } else {

        c->fd = creat(map_path, 0666);

        if (c->fd == -1) {
            perror("[!] creat");
            exit(EXIT_FAILURE);
        }

        map_write_signature(c);
    }

    if (c->fd == -1) {
        perror("[!] open");
        exit(EXIT_FAILURE);
    }

    c->offset = 0;

    stream = fopencookie(c, "wb+", map_func);

    if (stream == NULL) {
        perror("fopencookie");
        exit(EXIT_FAILURE);
    }

    return stream;
}

int map_write_signature(void *c) {
    
    struct map_cookie *cookie = c;
    int size = strlen(MAP_SIGNATURE);

    if (write(cookie->fd, MAP_SIGNATURE, size) == -1) {
        perror("[!] Write");
        exit(EXIT_FAILURE);
    }

    return 0;
}

int map_check_signature(void *c) {

    struct map_cookie *cookie = c;

    unsigned char r_sig[MAP_SIGNATURE_LEN];

    if (read(cookie->fd, r_sig, MAP_SIGNATURE_LEN) == -1) {
        perror("[!] Read");
        exit(EXIT_FAILURE);
    }

    if (memcmp(r_sig, MAP_SIGNATURE, MAP_SIGNATURE_LEN) != 0) {
        return -1;
    }

    return 0;
}
