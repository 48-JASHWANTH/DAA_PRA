/*5.	Job scheduling Consider the problem of scheduling n jobs of known deadlines d1, d2,...,dn for execution by a single processor. You will earn a profit if a job is completed by its deadline. The jobs can be executed in any order, one job at a time. You want to find a schedule that maximizes the profit. Implement a greedy algorithm for this problem. */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Structure to represent a job
struct Job {
  int deadline;
  int profit;
};

// Comparator function for sorting jobs by decreasing profit
bool compareJobs(Job a,Job b) { return a.profit > b.profit; }

// Function to schedule jobs and find maximum profit
void scheduleJobs(vector<Job> &jobs) {
  // Sort jobs in decreasing order of profit
  sort(jobs.begin(), jobs.end(), compareJobs);

  int n = jobs.size();
  vector<bool> slot(n, false); // Track available time slots

  int maxProfit = 0;
  for (int i = 0; i < n; ++i) {
    // Find a free slot for the current job (start from the last possible)
    for (int j = min(n - 1, jobs[i].deadline - 1); j >= 0; --j) {
      if (slot[j] == false) {
        slot[j] = true; // Mark slot as occupied
        maxProfit += jobs[i].profit;
        break;
      }
    }
  }

  cout << "Maximum profit: " << maxProfit << endl;
}

int main() {
  int numJobs;
  cout << "Enter the number of jobs: ";
  cin >> numJobs;

  vector<Job> jobs(numJobs);
  

  for (int i = 0; i < numJobs; i++) {
    cout << "Enter job " << i + 1 << " details (deadline profit): ";
    cin >> jobs[i].deadline >> jobs[i].profit;
  }

  scheduleJobs(jobs);

  return 0;
}