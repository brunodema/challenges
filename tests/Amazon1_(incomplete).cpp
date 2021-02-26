using namespace std;
/*
 * Complete the 'connectedSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING_ARRAY edges
 */
#include <iostream>
#include <string>
#include <vector>

struct Node {
  int value = 0;
  Node *parent = nullptr;
  Node *child = nullptr;
};

void parseInput(int n, vector<string> &edges, vector<Node> &nodes) {
  for (auto &s : edges) {
    auto a = int(s.front()) - 48;
    auto b = int(s.back()) - 48;
    if (nodes[a].child != nullptr) { // this is a 'double-parent', makes it to
                                     // be a child of someone else
      nodes[a].parent = &nodes[b];
      nodes[b].child = &nodes[a];
      continue;
    }
    nodes[a].child = &nodes[b];
    nodes[b].parent = &nodes[a];
  }
}

int connectedSum(int n, vector<string> edges) {
  vector<Node> nodes(n + 1);
  for (int i = 1; i <= n; ++i) {
    nodes[i].value = i;
  }
  parseInput(n, edges, nodes);

  double total_cost = 0;

  for (int i = 1; i <= n; ++i) {
    if (nodes[i].parent == nullptr) { // it's a root
      int counter = 1;
      auto *current_node = &nodes[i];
      cout << current_node->value << " ";
      while (current_node->child != nullptr) {
        current_node = current_node->child;
        cout << current_node->value << " ";
        ++counter;
      }
      total_cost += ceil(sqrt(counter));
      cout << endl;
    }
  }

  return total_cost;
}

int main() {

  int n = 8;

  vector<string> edges = {"8 1", "5 8", "7 3", "8 6"};

  int result = connectedSum(n, edges);

  cout << result << "\n";

  return 0;
}