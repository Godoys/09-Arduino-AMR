#ifndef MAP_STREAM
#define MAP_STREAM

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAP_SIGNATURE "\x4D\x41\x50\x05\xFF\xFF"
#define MAP_SIGNATURE_LEN 6

/*
 * Struct that represents a cookie for fopencookie.
 *
 * @param int fd file descriptor.
 * @param off_t offset file offset.
*/

struct map_cookie
{
    int fd;
    off_t offset;
};

/*
 * Writes BUF of size SIZE to file represented by C.
 *
 * @param void *c structure containing map reference.
 * @param const char *buf buffer containing data to be written.
 * @param size_t size size of buf.
 *
 * @return the number of bytes copied from buf, or 0 on error.
*/

ssize_t map_write(void *c, const char *buf, size_t size);

/*
 * Reads data from C and stores at BUF with size SIZE.
 *
 * @param void *c structure containing map reference.
 * @param char *buf buffer for storing read info.
 * @param size_t size size of buffer.
 *
 * @return the number of bytes copied into buf, 0 on end of file, or -1 on error.
*/

ssize_t map_read(void *c, char *buf, size_t size);

/*
 * Updates the offset of the file based on OFFSET and WHENCE.
 *
 * @param void *c structure containing map reference.
 * @param off_t *offset specifies new file offset.
 * @param int whence
 *
 * @return 0 on success, and -1 on error.
*/

int map_seek(void *c, off_t *offset, int whence);

/*
 * Closes the file descriptor and frees up cookie memory.
 *
 * @param void *c structure containing map reference.
 *
 * @return 0 on success, and EOF on error.
*/

int map_close(void *c);

/*
 * Creates a stream with the custom defined functions.
 *
 * @param char *map_path path to the file to be opened.
 *
 * @return stream created with custom functions.
*/

FILE *map_open(char *map_path);

/* 
 * Writes the MAP signature to the file.
 *
 * @param void *c structure containing map reference.
 *
 * @return 0 in case of success, -1 otherwise.
*/

int map_write_signature(void *c);

/* 
 * Checks wether the given file has the correct MAP signature.
 *
 * @param void *c structure containing map reference.
 *
 * @return 0 in case of success, -1 otherwise
*/

int map_check_signature(void *c);

#endif
