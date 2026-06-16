#include "map.h"
#include "map_stream.h"

int main(int argc, char *argv[])
{
    FILE *stream = map_open("/home/godoy/Documents/01-Adventures/09-AMR/meta-amr/recipes-core/files/src/rsc/sample.map");

    if (stream == NULL) {
        perror("[!] Error opening file");
        exit(EXIT_FAILURE);
    }

    struct point *p;
    p->x = 10;
    p->y = 10;

    map_populate(stream, p);

    fclose(stream);

    return 0;
}

