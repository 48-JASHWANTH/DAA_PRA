/*10.	Write a program that uses dynamic programming algorithm to solve the optimal binary search tree problem.*/

//https://youtu.be/wAy6nDMPYAE?si=Sz44EuHt3VjvLbgy
//https://youtu.be/UU7r-Li8t-A?si=8JEyhweBjKpQBzdQ
//https://www.geeksforgeeks.org/optimal-binary-search-tree-dp-24/


#include <bits/stdc++.h>
using namespace std;

int sum(int freq[], int i, int j) { 
	int s = 0; 
	for (int r = i; r <= j; r++) 
	s += freq[r]; 
	return s; 
}  
 
int optCost(int freq[], int i, int j) {  
	if(j<i) return 0;
	if(i==j) return freq[i];
	int fsum = sum(freq,i,j);
	int mini = INT_MAX;
	for(int k=i;k<=j;k++){
		int cost = optCost(freq,i,k-1) + optCost(freq,k+1,j);
		mini = min(mini,cost);
	}
	return mini+fsum;
} 

int optimalSearchTree(int keys[], int freq[], int n) { 
	return optCost(freq,0,n-1);
} 

int main() 
{ 
	int n;
    cout << "Enter the number of keys: ";
    cin >> n;
    
    int keys[n];
    int freq[n];
    
    cout << "Enter the keys: ";
    for (int i = 0; i < n; i++) {
        cin >> keys[i];
    }

    cout << "Enter the frequencies: ";
    for (int i = 0; i < n; i++) {
        cin >> freq[i];
    }

	cout << "Cost of Optimal BST is "<< optimalSearchTree(keys, freq, n); 
	return 0; 
} 