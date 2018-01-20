#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

void vectorInit(struct vector *vec) {
  vec->data = NULL;
  vec->size = 2;
  vec->count = 0;
  vec->data = calloc(sizeof(void*), vec->size);
}

void vectorInsert(struct vector *vec, void *elem) {
  if (vec->size == vec->count) {
    vec->size = vec->count * 2;
    vec->data = realloc(vec->data, sizeof(void*) * vec->size);
  }
  vec->data[vec->count] = elem;
  vec->count++;
}


void* vectorGet(struct vector *vec, int index) {
  if(index >= vec->count) {
    return NULL;
  }
  return vec->data[index];
}

void vectorSet(struct vector *vec, int index, void *elem) {
  if (index >= vec->count) {
    return;
  }
  vec->data[index] = elem;
}

void vectorFree(struct vector *vec) {
  free(vec->data);
  vec->count = 0;
  vec->size = 0;
  vec->data = NULL;
}
