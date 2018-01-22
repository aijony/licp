#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

struct vector{
  void** data;
  size_t size;
  size_t count;
};

void vectorInit(struct vector *vec);
void vectorInsert(struct vector *vec, void *elem);
void vectorAppend(struct vector *vecA, struct vector *vecB);
void* vectorGet(struct vector *vec, int index);
void vectorSet(struct vector *vec, int index, void *elem);
int vectorLength(struct vector *vec);
void vectorFree(struct vector *vec);
int vectorCompare(struct vector *vecA, struct vector * vecB);

#endif /* VECTOR_H */
