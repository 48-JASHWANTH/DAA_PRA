/*6.	Implement 0/1 Knapsack problem using Greedy Method.*/


//https://youtu.be/oTTzNMHM05I?si=Wjbffv5SFnPRpiMe
//https://youtu.be/u9GkcICYrgQ?si=n2TDy5FliyAS5Rrf


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define a structure to represent an item with weight and value
struct Item {
    int weight;
    int value;
};

// Function to compare items based on value-to-weight ratio
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Function to calculate the maximum value in the knapsack
double fractionalKnapsack(int capacity, vector<Item> items) {
    // Sort items based on value-to-weight ratio
    sort(items.begin(), items.end(), compare);

    int currentWeight = 0;  // Current weight in knapsack
    double totalValue = 0.0; // Total value in knapsack

    // Loop through all items
    for (Item item : items) {
        if (currentWeight + item.weight <= capacity) {
            // If adding the whole item doesn't exceed capacity, add it
            currentWeight += item.weight;
            totalValue += item.value;
        } else {
            // If adding the whole item exceeds capacity, add fractional part
            int remainingWeight = capacity - currentWeight;
            totalValue += item.value * ((double)remainingWeight/item.weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    int n; // Number of items
    int capacity; // Capacity of the knapsack

    cout << "Enter the number of items: ";
    cin >> n;

    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    vector<Item> items(n);

    cout << "Enter the weight and value of each item:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << " details(weight & value):";
        cin >> items[i].weight>> items[i].value;
    }

    double maxValue = fractionalKnapsack(capacity, items);

    cout << "The maximum value that can be obtained in the knapsack is: " << maxValue << endl;

    return 0;
}
