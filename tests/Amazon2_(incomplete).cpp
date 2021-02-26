using namespace std;

/*
 * Complete the 'doesCircleExist' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY commands as parameter.
 */
#include <iostream>
#include <string>
#include <vector>

// 23 = G
// 34 = R
// 28 = L

struct Moves {
  int x_move;
  int y_move;
};

void parseCommands(const vector<string> &commands, vector<int> &moves) {
  for (auto &command : commands) {
    for (auto &c : command) {
      moves.push_back(c - 48);
    }
  }
  return;
}

pair<int, int> move(vector<int> &moves, int index,
                    const vector<Moves> &possible_moves) {
  static pair<int, int> current_coord = {0, 0};
  if (index == moves.size()) {
    return current_coord;
  } else {
    switch (moves[index]) {
    case 0: // G
      current_coord = current_coord.break;
    case 1: // R
      break;
    case 2: // L
      break;
    }
  }
}

vector<string> doesCircleExist(vector<string> commands) {
  pair<int, int> init_coord = {0, 0};
  pair<int, int> final_coord = {0, 0};
  vector<int> moves;
  vector<Moves> possible_moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  parseCommands(commands, moves);

  for (int i = 0; i < moves.size(); ++i) {
    final_coord = move(moves, i, possible_moves);
  }
  return {};
}

int main() {

  vector<string> commands = {"GRGL"};

  vector<string> result = doesCircleExist(commands);

  cout << "\n";

  return 0;
}
