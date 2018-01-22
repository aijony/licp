#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include "tree.h"
#include "concat.h"
#include "vector.h"

struct node* newNode(char* data) {
  struct node* node = malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return node;
}

int heightTree(struct node *tree) {
  if(tree) {
    int heightLeft = heightTree(tree->right);
    int heightRight = heightTree(tree->left);
    if(heightLeft >= heightRight) {
      return heightLeft + 1;
    }
    else {
      return heightRight + 1;
    }
  }
  return 0;
}

char* printTree(struct node *tree) {
  struct node *toPrint = tree;
  fillTree(toPrint, heightTree(toPrint));

  char* out = "";

  int height = heightTree(toPrint);
  for(int layerCount = 0; layerCount <= height; layerCount++) {
    int padding = ((int) pow(2, (height - layerCount)));
    char paddingStr[padding];
    memset(paddingStr, ' ', sizeof(paddingStr));
    paddingStr[sizeof(paddingStr) - 1] = '\0';

    struct vector layer = layerTree(toPrint, layerCount - 1);
    for(int i = 0; i < vectorLength(&layer); i++){
      char* sec = concat(concat(paddingStr, vectorGet(&layer, i)), paddingStr);
      out = concat(out, sec);
      out = concat(out, " ");
    }
    out = concat(out, "\n");
  }
  return out;
}

void fillTree(struct node *tree, int height) {
  if(height > 1) {
    if (tree->left == NULL) {
      tree->left = newNode("_");
    }
    if (tree->right == NULL) {
      tree->right = newNode("_");
    }
    height = height - 1;
    fillTree(tree->left, height);
    fillTree(tree->right, height);
  }
}

struct vector layerTree(struct node *tree, int layer) {
  if (layer > heightTree(tree) || layer < 0) {
    struct vector vecOut;
    vectorInit(&vecOut);
    return vecOut;
  }
  else if (layer == 0) {
    struct vector vecOut;
    vectorInit(&vecOut);
    vectorInsert(&vecOut, tree->data);
    return vecOut;
  }
  else {
    layer--;
    struct vector vecOut = layerTree(tree->left, layer);
    struct vector vecAppend = layerTree(tree->right, layer);
    vectorAppend(&vecOut, &vecAppend);
    return vecOut;
  }
}

char* printTestTree() {
  struct node* root = newNode("a");
  root->left = newNode("b");
  root->right = newNode("c");
  root->left->left = newNode("d");
  root->right->right = newNode("e");
  root->right->right->right = newNode("f");
  return printTree(root);
}
