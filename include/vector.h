#ifndef VECTOR_H
#define VECTOR_H

struct vector{
  void** data;
  size_t size;
  size_t count;
};

void vectorInit(struct vector *vec);
void vectorInsert(struct vector *vec, void *elem);
void* vectorGet(struct vector *vec, int index);
void vectorSet(struct vector *vec, int index, void *elem);
void vectorFree(struct vector *vec);

#endif /* VECTOR_H */
