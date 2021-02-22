/*

Recursion: Fibonacci Numbers

https://www.hackerrank.com/challenges/ctci-fibonacci-numbers/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=recursion-backtracking

this one is pretty standard... could try to solve it using queue?

*/

#include <iostream>

using namespace std;

int fibonacci(int n) {
  // Complete the function.
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  }
  return fibonacci(n - 2) + fibonacci(n - 1);
}

int main() {
  int n;
  cin >> n;
  cout << fibonacci(n);
  return 0;
}
