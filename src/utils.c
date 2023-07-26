#include "../include/utils.h"
#include <stdlib.h>
#include "../include/ToyShell.h"

void* SafeMalloc(size_t malloc_size) {
  void* malloc_memory = malloc(sizeof(malloc_size));
  if(!malloc_memory && malloc_size) {
    printf("Failed to malloc memory!\n");
    exit(-1);
  }
  return malloc_memory;
}

void* SafeRealloc(void* pointer, size_t malloc_size) {
  void* realloc_memory = realloc(pointer, malloc_size);
  if(!realloc_memory && malloc_size) {
    printf("Failed to realloc memory!\n");
    exit(-1);
  }
  return realloc_memory;
}

int FlushStdin() {
  int c;
  while((c = getchar()) != '\n'); 
  return SUCCESS;
}
