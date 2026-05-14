#ifndef MAP_STREAM
#define MAP_STREAM

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#include <unistd.h>
#include <fcntl.h>

#define MAP_SIGNATURE "\x4D\x41\x50\x05\xFF\xFF"
#define MAP_SIGNATURE_LEN 6

struct map_cookie
{
    int fd;           /* File descriptior returned from open() */ 
    off_t offset;     /* Current file offset in file */
};

ssize_t map_write(void *c, const char *buf, size_t size);

ssize_t map_read(void *c, char *buf, size_t size);

int map_seek(void *c, off_t *offset, int whence);

int map_close(void *c);

FILE *map_open(char *map_path);

/* 
 * Writes to the file the MAP signature.
 *
 * In case of sucess returns 0; -1 otherwise
*/

int map_write_signature(void *c);

/*
 * Checks wether the given file has the correct
 * MAP signature.
 * 
 * In case of success returns 0; -1 otherwise.
 */

int map_check_signature(void *c);

#endif
