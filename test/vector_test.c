#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vector.h"

int main() {
  struct vector vec;
  vectorInit(&vec);

  vectorInsert(&vec, "1");
  return (strcmp("1", vectorGet(&vec, 0)));
}
