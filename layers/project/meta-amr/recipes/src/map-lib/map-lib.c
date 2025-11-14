#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *open_map(char *file_name, char *mode) {
  // File pointer to be returned.
  FILE *file_ptr;

  // Attemps to open file.
  file_ptr = fopen(file_name, mode);

  // Fail condition.
  if (file_ptr == NULL) {
    if (strcmp(mode, "w") == 0) {
      file_ptr = open_map(file_name, "w");
    } else {
      exit(1);
    }
  }

  return file_ptr;
}

void close_map(FILE *file) { fclose(file); }

int main() {}
