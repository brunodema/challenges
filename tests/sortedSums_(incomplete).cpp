/*
THE LESSON HERE IS: WATCH OUT FOR OVERLOW!!!
use some of these functions next time:

1. ( a + b ) % c = ( ( a % c ) + ( b % c ) ) % c
2. ( a * b ) % c = ( ( a % c ) * ( b % c ) ) % c
3. ( a – b ) % c = ( ( a % c ) - ( b % c ) ) % c ( see notes at bottom )
4. ( a / b ) % c NOT EQUAL TO ( ( a % c ) / ( b % c ) ) % c

*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'sortedSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

int individual_sum(int i, vector<int> a_redux) {
  int ret = 0;
  std::sort(a_redux.begin(), a_redux.end());
  int multiplier = 1;
  int temp = 0;
  for (int ii = 0; ii < i; ++ii) {
    temp = multiplier * a_redux[ii];

    ret = ((ret % 1000000007) + (temp % 1000000007)) % 1000000007;

    ++multiplier;
  }

  return ret;
}

int sortedSum(vector<int> a) {
  int ret = 0;
  int returned_value = 0;
  vector<int> temp_vec;
  for (int i = 1; i <= a.size(); ++i) {
    temp_vec.push_back(a[i - 1]);
    sort(temp_vec.begin(), temp_vec.end());
    returned_value = individual_sum(i, temp_vec);
    ret = ((ret % 1000000007) + (returned_value % 1000000007)) % 1000000007;
  }
  return ret;
}

int main()