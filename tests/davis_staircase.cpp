/*

Recursion: Davis' Staircase

https://www.hackerrank.com/challenges/ctci-recursive-staircase/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=recursion-backtracking

*/

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

static std::vector<int> steps = {};

// Complete the stepPerms function below.
int stepPerms(int n) {
  if (n <= 0) {
    return 0;
  }
  if (n == 1) {
    steps[1] = 1;
    return 1;
  }
  if (n == 2) {
    steps[2] = 2;
    return 2;
  }
  if (n == 3) {
    steps[3] = 4;
    return 4;
  }
  if (steps[n] != -1) {
    return steps[n];
  }
  steps[n] = stepPerms(n - 1) + stepPerms(n - 2) + stepPerms(n - 3);

  return steps[n];
}

int main() {
  int s[] = {15, 20, 27};

  for (int s_itr = 0; s_itr < sizeof(s) / sizeof(*s); s_itr++) {
    steps.resize(s[s_itr] + 1, -1);
    int res = stepPerms(s[s_itr]);

    cout << res << "\n";
  }

  return 0;
}

/*
I had to alter the original main function to compile it here:

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int s;
    cin >> s;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int s_itr = 0; s_itr < s; s_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        steps.resize(n + 1, -1);
        int res = stepPerms(n);

        fout << res << "\n";
    }

    fout.close();

    return 0;
}
*/
