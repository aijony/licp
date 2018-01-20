#ifndef TREE_H
#define TREE_H

struct node {
  char data;
  struct node *left;
  struct node *right;
};

struct node* newNode(char data);

void printTree(struct node* tree);

void printTestTree();

#endif /* TREE_H */
