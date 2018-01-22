#include "parser.h"
#include "vector.h"

int isBracket_test();
int isSpace_test();
int fragementSymbols_test();

int main() {
  int testVal =
      isBracket_test() +
      isSpace_test() +
      fragementSymbols_test();

  return testVal;
}

int fragementSymbols_test() {
  char* test = "(+ 3 x)";

  struct vector expected;
  vectorInit(&expected);

  vectorInsert(&expected, "(");
  vectorInsert(&expected, "+");
  vectorInsert(&expected, "3");
  vectorInsert(&expected, "x");
  vectorInsert(&expected, ")");

  struct vector result = fragmentSymbols(test);

  return vectorCompare(&expected, &result);
}

int isBracket_test() {
  int testVal =
      isBracket('(') +
      isBracket(')') +
      isBracket('{') +
      isBracket('}') +
      isBracket('[') +
      isBracket(']');
  return (testVal == 0);
}

int isSpace_test() {
  return 1 - isSpace(' ');
}
