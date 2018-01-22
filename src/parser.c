#include <stdio.h>
#include <stdlib.h>

#include "parser.h"
#include "tree.h"
#include "vector.h"
#include "concat.h"

struct node root = {"(", NULL, NULL};
struct node *lastNode = &root;

int symbolLoop(char* input) {

  struct vector vecSym = fragmentSymbols(input);
  
  while(*input) {
    char currChar = *input++;
    analyzeSymbol(currChar);
  }
  return 0;
}

void analyzeSymbol(char input) {
}

struct vector fragmentSymbols(char* input) {
  struct vector expression;
  vectorInit(&expression);

  char* currWord = "";

  while(*input) {
    char currChar = *input++;
    char castCurrChar[1] = {currChar};
    if (isBracket(currChar)) {
      vectorInsert(&expression, castCurrChar);
    }
    else if (isSpace(currChar)) {
      vectorInsert(&expression, currWord);
      free(currWord);
      char* currWord = "";

      // HACK Compiler doesn't think variable is used.
      if(currWord){}
    }
    else {
      currWord = concat(currWord, castCurrChar);
    }
  }
  free(currWord);
  return expression;
}

int isBracket(char input) {
  return
      input == '(' ||
      input == ')' ||
      input == '{' ||
      input == '}' ||
      input == '[' ||
      input == ']';
}

int isSpace(char input){
  return input == ' ';
}

