/*9.	Write program to find optimal ordering of matrix multiplication. (Note: Use Dynamic programming method).*/

//https://youtu.be/_WncuhSJZyA?si=Ew42V-FhYqOoE2Ev
//https://youtu.be/q6iGuCxTPlw?si=BPeNaisYiH-C44oz
//https://youtu.be/eKkXU3uu2zk?si=12YcURCTBad-nvZc

#include <bits/stdc++.h>
using namespace std;

void printParanthesis(int i, int j, int n, vector<vector<int>> s, char &ch) {
  if (i == j) {
    cout << ch++;
    return;
  }
  cout << "(";
  printParanthesis(i, s[i][j], n, s, ch);
  printParanthesis(s[i][j]+1, j, n, s,ch);
  cout << ")";
}

int main() {
  int n;
  cout << "Enter size : ";
  cin >> n;
  vector<int> arr(n);
  cout << "Enter matrix dimensions\n";
  for (int i=0;i<n;i++){
    cin >> arr[i];
  }
  vector<vector<int>> m(n, vector<int>(n, 0)),s(n, vector<int>(n, 0));
  for (int i=1;i<n-1;i++){
    for(int j=1;j<n-i;j++) {
      int r = i+j; 
      int mini = INT_MAX;
      for(int k=j;k<r;k++) {
        int q = m[j][k]+m[k+1][r]+arr[j-1]*arr[k]*arr[r];
        if(q<mini) {
          mini = q;
          s[j][r] = k;
        }
      }
      m[j][r] = mini;
    }
  }
  cout << "Minimum cost is : " << m[1][n-1] << endl;
  char ch = 'A';
  cout << "Optimal paranthesization is : ";
  printParanthesis(1,n-1,n,s,ch);
}