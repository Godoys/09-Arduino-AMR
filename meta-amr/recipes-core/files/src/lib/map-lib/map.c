#include "map.h"
#include "map_stream.h"

int map_populate(void *s, void *p)
{
    FILE *stream = s;
    struct point *end_point = p;

    size_t map_size = end_point->x * end_point->y;

    struct point *buf = malloc(sizeof(struct point) * map_size);

    int points_counter = 0;

    while (points_counter < map_size) {
        for (int y = 0; y < end_point->y; y++) {
            for (int x = 0; x < end_point->x; x++) {
                struct point *new_point;
                new_point->x = x;
                new_point->y = y;
                new_point->v = false;

                buf[points_counter] = *new_point;

                points_counter += 1;
            }
        }
    }

    if (fwrite(buf, sizeof(struct point), map_size, stream) < 1){
        perror("[!] Write");
        exit(EXIT_FAILURE);
    }

    free(buf);

    return 0;
}
