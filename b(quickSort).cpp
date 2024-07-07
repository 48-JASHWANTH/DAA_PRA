/*2.	Sort a given set of elements using the Quicksort method and determine the time required to sort the elements. Repeat the experiment for different values of n and different methods of pivot selection to analyse the behaviour of quick sort. Plot a graph of the time taken versus n. The elements can be read from a file and can be generated using the random number generator.*/

//https://www.youtube.com/watch?v=WIrA4YexLRQ

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



// Choose pivot based on the selected strategy
int choosePivot(vector<int> &arr, int low, int high, int pivotType) {
    switch (pivotType) {
        case 1: // First element as pivot
            return low;
        case 2: // Last element as pivot
            return high;
        case 3: // Median of three
            int mid = low + (high - low) / 2;
            if ((arr[low] < arr[mid] && arr[mid] < arr[high]) || (arr[high] < arr[mid] && arr[mid] < arr[low]))
                return mid;
            else if ((arr[mid] < arr[low] && arr[low] < arr[high]) || (arr[high] < arr[low] && arr[low] < arr[mid]))
                return low;
            else
                return high;
    }
    return low;
}

// Partition function with pivot selection
int partition(vector<int> &arr, int low, int high, int pivotType) {
    int pivotIndex = choosePivot(arr, low, high, pivotType);
    int pivot = arr[pivotIndex];

    // Move pivot to the start of the partition
    swap(arr[pivotIndex], arr[low]);

    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i < high) {
            i++;
        }
        while (arr[j] > pivot && j > low) {
            j--;
        }
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    // Place pivot in its correct position
    swap(arr[low], arr[j]);
    return j;
}

// QuickSort algorithm
void qs(vector<int> &arr, int low, int high, int pivotType) {
    if (low < high) {
        int pIndex = partition(arr, low, high, pivotType);
        qs(arr, low, pIndex - 1, pivotType);
        qs(arr, pIndex + 1, high, pivotType);
    }
}

// QuickSort wrapper
vector<int> quickSort(vector<int> arr, int pivotType) {
    qs(arr, 0, arr.size() - 1, pivotType);
    return arr;
}

int main() {
    int n, pivotType;
    
    // User input for the number of elements
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // User input for pivot selection strategy
    cout << "Choose pivot strategy:\n";
    cout << "1. First Element as Pivot\n";
    cout << "2. Last Element as Pivot\n";
    cout << "3. Median of Three\n";
    cout << "Enter your choice (1-3): ";
    cin >> pivotType;

    // Output the array before sorting
    cout << "Before Using Quick Sort: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Perform quicksort
    arr = quickSort(arr, pivotType);

    // Output the array after sorting
    cout << "After Using Quick Sort: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}