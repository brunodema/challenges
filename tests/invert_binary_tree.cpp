// https://www.geeksforgeeks.org/write-an-efficient-c-function-to-convert-a-tree-into-its-mirror-tree/
// I pretty much copied everything... I just reworked the 'invert' function to
// work with a queue

#include <cstddef>
#include <iostream>
#include <queue>
using namespace std;

/* A node contains the value, left and right pointers */
struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};

/* Creates a new node */
struct Node *newNode(int data) {
  Node *node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return (node);
}

void invert(struct Node *node) {
  if (node == NULL)
    return;
  auto temp = node->left;
  node->left = node->right;
  node->right = temp;
}

/* print InOrder binary tree traversal.*/
void print_tree(struct Node *node) {
  if (node == NULL)
    return;

  print_tree(node->left);
  cout << node->data << " ";
  print_tree(node->right);
}

int main() {
  struct Node *root = newNode(2);
  root->left = newNode(1);
  root->right = newNode(4);
  root->right->left = newNode(3);
  root->right->right = newNode(5);

  cout << "Inorder traversal of the constructed"
       << " tree is" << endl;
  print_tree(root);

  /* Invert the tree */
  std::queue<Node *> queue;
  queue.push(root);

  while (!queue.empty()) {
    auto current = queue.front();
    invert(current);
    queue.pop();
    if (current->left != NULL) {
      queue.push(current->left);
    }
    if (current->right != NULL) {
      queue.push(current->right);
    }
  }

  cout << endl;

  cout << "Inorder traversal of the inverted tree"
       << " is \n";

  print_tree(root);

  return 0;
}

/**
About std::queue:

When you 'push', you add the pushed element to the back of the list.

When you 'pop', you remove the element at the front of the list.

To process things as expected, do whatever you want with the front object
(queue.front()), then pop it.

 */