#include <string.h>

#include "concat.h"

int main() {
  char* check = "You complete me <3";

  char* str1 = "You comp";
  char* str2 = "lete me";
  char* str3 = " <3";

  char* strConcat = concat(str1, concat(str2, str3));
  return (strcmp(check, strConcat));
}
