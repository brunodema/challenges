/*

Tree: Level Order Traversal

// https://www.hackerrank.com/challenges/tree-level-order-traversal/problem

I had more problems adapting the 'main' function than solving this one :p


*/

#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
  int data;
  Node *left;
  Node *right;
  Node(int d) {
    data = d;
    left = NULL;
    right = NULL;
  }
};

class Solution {
public:
  Node *insert(Node *root, int data) {
    if (root == NULL) {
      return new Node(data);
    } else {
      Node *cur;
      if (data <= root->data) {
        cur = insert(root->left, data);
        root->left = cur;
      } else {
        cur = insert(root->right, data);
        root->right = cur;
      }

      return root;
    }
  }
  /*
  class Node {
      public:
          int data;
          Node *left;
          Node *right;
          Node(int d) {
              data = d;
              left = NULL;
              right = NULL;
          }
  };
  */
  void levelOrder(Node *root) {
    queue<Node *> queue;
    queue.push(root);
    while (!queue.empty()) {
      auto node = queue.front();
      levelOrderAuxa(node, queue);
      queue.pop();
    }
  }

  void levelOrderAuxa(Node *node, queue<Node *> &_queue) {
    cout << node->data << " ";
    if (node->left != NULL) {
      _queue.push(node->left);
    }
    if (node->right != NULL) {
      _queue.push(node->right);
    }
  }

}; // End of Solution

int main() {

  Solution myTree;
  Node *root = NULL;

  int t;
  int data;

  std::cin >> t;

  while (t-- > 0) {
    std::cin >> data;
    root = myTree.insert(root, data);
  }

  myTree.levelOrder(root);
  return 0;
}