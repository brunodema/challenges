// could not finish this one :(
// maybe implement the hungarian method to solve it?

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'getMinCost' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY crew_id
 *  2. INTEGER_ARRAY job_id
 */

int findNearestRepair(int reference_point, vector<int> &available_jobs) {
  bool found = false;
  int pos;

  if (available_jobs[reference_point] != -1) {
    available_jobs[reference_point] = -1;
    return 0;
  }
  int offset = 1;
  while (offset < available_jobs.size()) // terrible comparison to make
  {

    if (reference_point - offset > 0) {
      if (available_jobs[reference_point - offset] != -1) {
        available_jobs[reference_point - offset] = -1;
        return offset;
      }
    } else if (reference_point + offset < available_jobs.size()) {
      if (available_jobs[reference_point + offset] != -1) {
        available_jobs[reference_point + offset] = -1;
        return offset;
      }
    }
    ++offset;
  }
  return -1; // impossible
}

long getMinCost(vector<int> crew_id, vector<int> job_id) {
  long min_cost = 0;

  int max = 0;
  for (int i = 0; i < job_id.size(); ++i) {
    job_id[i] > max ? max = job_id[i] : max = max;
  }

  vector<int> positions(max + 1, -1);
  for (auto job : job_id) {
    positions[job] = job;
  }

  vector<bool> skip(crew_id.size(), false);

  for (int i = 0; i < crew_id.size(); ++i) {
    if (positions[crew_id[i]] != -1) {
      positions[crew_id[i]] = -1;
      skip[crew_id[i]] = true;
    }
  }

  for (int i = 0; i < crew_id.size(); ++i) {
    if (!skip[i]) {
      min_cost += findNearestRepair(crew_id[i], positions);
    }
  }
  return min_cost;
}

int main() {
  // vector<int> crew_id = {5, 1, 4, 2};
  // vector<int> job_id = {4, 7, 9, 10};

  vector<int> crew_id = {5, 3, 1, 4, 6};
  vector<int> job_id = {9, 8, 3, 15, 1};

  long result = getMinCost(crew_id, job_id);

  cout << result << "\n";

  return 0;
}
