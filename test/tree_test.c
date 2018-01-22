#include <stdio.h>

#include "tree.h"
#include "vector.h"

int test_height();
int test_layerTree();

int main() {
  int testVal =
      test_height() +
      test_layerTree();
  return testVal;
}

int test_height() {
  struct node* tree = newNode("a");
  tree->left = newNode("b");
  tree->right = newNode("c");
  tree->left->left = newNode("d");

  int expectedHeight = 3;

  fillTree(tree, expectedHeight);

  int height = heightTree(tree);

  return height - expectedHeight;
}

int test_layerTree () {
  struct vector expected;
  vectorInit(&expected);
  vectorInsert(&expected, "b");
  vectorInsert(&expected, "c");

  struct node* tree = newNode("a");
  tree->left = newNode("b");
  tree->right = newNode("c");

  struct vector result = layerTree(tree, 1);
  return
      vectorLength(&result) - vectorLength(&result) +
      1 - vectorCompare(&result, &expected);
}
