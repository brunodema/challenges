// unfinished

#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

struct gap_coord {
  gap_coord *conflict; // points to other conflicts
  int x;
  int y;
};

struct fill_section {
  fill_section(const gap_coord &begin, const gap_coord &end)
      : _begin(begin), _end(end) {
    // should not matter which direction it is
    lenght = abs(begin.x - end.x + begin.y - end.y);
  }

  gap_coord _begin;
  gap_coord _end;

  int lenght;
};

// Complete the crosswordPuzzle function below.
vector<string> crosswordPuzzle(vector<string> crossword, string words) {
  // 1. identify all gaps and map them somehow (vector_of_gaps)
  // 2. parse words into a set of strings (set_of_words)
  // 3. while all words are not inserted into the crossword, do:
  // 3.1 check for base recursion condition (all words inserted)
  // 3.2 choose a word and attempt to insert it
  // (checks involve the size of the word, and conflicting positions)
  // 3.3 if successful, recurse into the next word
  // 3,4 if not, backtrack
  return {};
}

int main() {
  vector<string> crossword = {
      "+-++++++++", "+-++++++++", "+-++++++++", "+-----++++", "+-+++-++++",
      "+-+++-++++", "+++++-++++", "++------++", "+++++-++++", "+++++-++++"};

  string words = "LONDON;DELHI;ICELAND;ANKARA";

  vector<string> result = crosswordPuzzle(crossword, words);

  for (int i = 0; i < result.size(); i++) {
    cout << result[i];

    if (i != result.size() - 1) {
      cout << "\n";
    }
  }

  cout << "\n";

  return 0;
}
