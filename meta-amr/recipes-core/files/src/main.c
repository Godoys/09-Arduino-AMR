#include "map_stream.h"

int main(int argc, char *argv[])
{
    FILE *stream = map_open("/home/godoy/Documents/01-Computer-Science/01-Projects/09-AMR/meta-amr/recipes-core/files/src/rsc/sample.map");

    if (stream == NULL) {
        perror("[!] Error opening file");
        exit(EXIT_FAILURE);
    }

    fclose(stream);

    return 0;
}

