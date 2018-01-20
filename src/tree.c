#include <stdlib.h>
#include <stdio.h>

#include "tree.h"

struct node* newNode(char data) {
  struct node* node = malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return node;
}

void printTree(struct node *tree) {
  if(tree) {
    putchar('{');
    putchar(tree->data);
    printTree(tree->left);
    putchar('}');
    printTree(tree->right);
    putchar('}');
  }
  else {
    putchar('{');
  }
}

void printTestTree() {
  struct node* root = newNode('a');
  root->left = newNode('b');
  root->right = newNode('c');
  root->left->left = newNode('d');
  printTree(root);
}
