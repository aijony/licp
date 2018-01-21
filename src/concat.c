#include <stdlib.h>
#include <string.h>

#include "concat.h"

char* concat(const char *head, const char *tail) {
  char *output = malloc(strlen(head)+strlen(tail)+1);
  //TODO Check for malloc errors
  strcpy(output, head);
  strcat(output, tail);
  return output;
}
