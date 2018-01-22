#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vector.h"


int compareA_test();
int compareB_test();
int append_test();
int simple_test();

int main() {
  int testVal =
      compareA_test() +
      compareB_test() +
      append_test() +
      simple_test();
  return testVal;
}

int compareA_test() {
  struct vector vecA;
  struct vector vecB;
  vectorInit(&vecA);
  vectorInit(&vecB);
  vectorInsert(&vecA, "1");
  vectorInsert(&vecA, "2");
  vectorInsert(&vecA, "3");
  vectorInsert(&vecB, "1");
  vectorInsert(&vecB, "2");
  vectorInsert(&vecB, "3");

  return 1 - vectorCompare(&vecA, &vecB);
}

int compareB_test() {
  struct vector vecA;
  struct vector vecB;
  vectorInit(&vecA);
  vectorInit(&vecB);
  vectorInsert(&vecA, "1");
  vectorInsert(&vecB, "1");
  vectorInsert(&vecA, "1");
  vectorInsert(&vecB, "2");

  return vectorCompare(&vecA, &vecB);
}

int append_test() {
  struct vector vecA;
  struct vector vecB;
  struct vector vecC;
  vectorInit(&vecA);
  vectorInit(&vecB);
  vectorInit(&vecC);
  vectorInsert(&vecA, "1");
  vectorInsert(&vecA, "2");
  vectorInsert(&vecB, "3");
  vectorInsert(&vecB, "4");
  vectorInsert(&vecC, "1");
  vectorInsert(&vecC, "2");
  vectorInsert(&vecC, "3");
  vectorInsert(&vecC, "4");
  vectorAppend(&vecA, &vecB);
  int testVal =
      vectorLength(&vecA) - vectorLength(&vecC)
      + 1 - vectorCompare(&vecA, &vecC);
  return testVal;
}

int simple_test() {
  struct vector vec;
  vectorInit(&vec);

  vectorInsert(&vec, "1");
  return (strcmp("1", vectorGet(&vec, 0)));
}
