#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void vectorAppend(struct vector *vecA, struct vector *vecB){
  int size = vecB->count;
  for(int i = 0; i < size; i++) {
    vectorInsert(vecA, vectorGet(vecB, i));
  }
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

int vectorLength(struct vector *vec) {
  return vec->count;
}

void vectorFree(struct vector *vec) {
  free(vec->data);
  vec->count = 0;
  vec->size = 0;
  vec->data = NULL;
}


int vectorCompare(struct vector *vecA, struct vector *vecB) {
  if (vectorLength(vecA) != vectorLength(vecB)) {
    return 0;
  }
  int checkSum = 0;
  for(int i = 0; i < vectorLength(vecA); i = i + 1) {
    checkSum += (memcmp(vectorGet(vecA, i), vectorGet(vecB, i), sizeof(vectorGet(vecA, i))) == 0);
  }
  return checkSum == vectorLength(vecA);
}
