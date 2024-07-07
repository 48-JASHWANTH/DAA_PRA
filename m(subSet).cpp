/*Find a subset of a given set S = {sl,s2,.....,sn} of n positive integers whose sum is equal to a given positive integer d. For example, if S= {1, 2, 5, 6, 8} and d = 9 there are two solutions{1,2,6}and{1,8}.A suitable message is to be displayed if the given problem instance doesn't have a solution.*/

#include <iostream>
#include <vector>

using namespace std;

void findSubsets(vector<int> &set, int n, int sum, vector<int> &subset) {
    // Base case: if the sum is 0, print the current subset
    if (sum == 0) {
        cout << "Subset with given sum: ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }

    // If no elements are left or sum becomes negative, return
    if (n == 0 || sum < 0) return;

    // Exclude the current element and move to the next
    findSubsets(set, n - 1, sum, subset);

    // Include the current element in the subset and recurse
    subset.push_back(set[n - 1]);
    findSubsets(set, n - 1, sum - set[n - 1], subset);

    // Backtrack: remove the last element
    subset.pop_back();
}


int main() {
    int n;
    cout<<"Enter size:";
    cin>>n;
    vector<int> set(n);
    cout<<"Enter elements:";
    for(int i=0;i<n;i++) cin>>set[i];
    int sum;
    cout<<"Enter sum:";
    cin>>sum;
    vector<int> subset;

    findSubsets(set, n, sum, subset);

    return 0;
}
