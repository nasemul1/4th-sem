#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Structure to represent an item
struct Item {
    int weight;
    int value;
};


// Function to compare items based on their value per unit weight
bool compareItems(const Item& item1, const Item& item2) {
    double valuePerUnitWeight1 = double(item1.value) / item1.weight;
    double valuePerUnitWeight2 = double(item2.value) / item2.weight;
    return valuePerUnitWeight1 > valuePerUnitWeight2;
}


// Function to calculate the maximum achievable value
double fractionalKnapsack(int capacity, vector<Item>& items) {
    // Sort items based on value per unit weight
    sort(items.begin(), items.end(), compareItems);


    double totalValue = 0.0;  // Total value achieved
    int currentWeight = 0;    // Current weight in the knapsack


    // Iterate through each item
    for (const Item& item : items) {
        // Check if the current item can be fully included
        if (currentWeight + item.weight <= capacity) {
            currentWeight += item.weight;
            totalValue += item.value;
        }
        // If the current item cannot be fully included, include a fraction of it
        else {
            int remainingCapacity = capacity - currentWeight;
            double fraction = double(remainingCapacity) / item.weight;
            currentWeight += remainingCapacity;
            totalValue += fraction * item.value;
            break;  // Knapsack is full, so exit the loop
        }
    }


    return totalValue;
}


// Main function
int main() {
    int numItems;
    cout << "Enter the number of items: ";
    cin >> numItems;


    vector<Item> items(numItems);


    cout << "Enter the weight and value of each item:\n";
    for (int i = 0; i < numItems; i++) {
        cout << "Item " << i + 1 << ":\n";
        cout << "Weight: ";
        cin >> items[i].weight;
        cout << "Value: ";
        cin >> items[i].value;
    }


    int capacity;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;


    double maxValue = fractionalKnapsack(capacity, items);


    cout << "Maximum achievable value: " << maxValue << endl;


    return 0;
}
