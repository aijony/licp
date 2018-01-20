#include <stdio.h>

#include "parser.h"
#include "tree.h"

struct node root = {'(', NULL, NULL};
struct node *lastNode = &root;

int symbolLoop(char* input) {

  while(*input) {
    char currChar = *input++;
    analyzeSymbol(currChar);
  }
  return 0;
}

void analyzeSymbol(char input) {

  struct node* nextNode = newNode(input);
  if(input == '+') {
    lastNode->right = nextNode;
  }
  else if(input == '~') {
    printTree(&root);
  }
  else {
    lastNode->left = nextNode;
  }
  lastNode = nextNode;
}

/* char[][] fragmentSymbols(char[] expr) { */
  
/* } */
