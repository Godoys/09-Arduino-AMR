#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *open_map(char *file_name, char *mode) {
  // Checks if file_name is a map file.
  if (strstr(file_name, ".map") == NULL) {
    printf("[!] File not in the correct format, expected .map file.");
    exit(1);
  }

  // File pointer to be returned.
  FILE *file_ptr;

  // Attemps to open file.
  file_ptr = fopen(file_name, mode);

  // Fail condition.
  if (file_ptr == NULL) {
    if (strcmp(mode, "w") == 0) {
      file_ptr = open_map(file_name, "w");
    } else {
      printf("[!] Error when opening file.");
      exit(1);
    }
  }

  return file_ptr;
}

void close_map(FILE *file) { fclose(file); }

// create_map assumes that the map starts at (0,0) and ends at
// (end_coordinate,end_coordinate).

FILE *create_map(char *map_name, int end_coordinate, int div) {
  // Creates new map file with map_name.
  char *file_name;

  if (strstr(map_name, ".map") == NULL) {
    file_name = strcat(map_name, ".map");
  } else {
    file_name = map_name;
  }

  FILE *map_ptr = open_map(file_name, "w");

  int div_counter = 1;
  int i = 0;

  // Write coordinates to map file.
  do {
    if (i == 0) {
      fprintf(map_ptr, "START_1\n");
    } else if (i % div == 0) {
      fprintf(map_ptr, "END_%d\n\n", div_counter);
      div_counter += 1;
      if (i + 1 < end_coordinate) {
        fprintf(map_ptr, "START_%d\n", div_counter);
      } else {
        break;
      }
    }
    fprintf(map_ptr, "%d,%d\n", i, i);
    i += 1;
  } while (i < end_coordinate + 1);

  close_map(map_ptr);

  return map_ptr;
}

int main() { FILE *m = create_map("t.map", 100, 10); }
