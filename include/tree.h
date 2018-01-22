#ifndef TREE_H
#define TREE_H

#include "vector.h"

struct node {
  char* data;
  struct node *left;
  struct node *right;
};

struct node* newNode(char* data);

int heightTree(struct node *tree);

char* printTree(struct node *tree);

void fillTree(struct node *tree, int height);

struct vector layerTree(struct node *tree, int layer);

char* printTestTree();


#endif /* TREE_H */
