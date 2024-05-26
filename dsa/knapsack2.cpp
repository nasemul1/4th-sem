#include <iostream>
#include <vector>
using namespace std;


// Structure to represent an item
struct Item {
    int cost;
    int weight;
};


// Function to calculate the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}


// Function to solve the 0/1 knapsack problem
int knapsack(int capacity, vector<Item>& items) {
    int n = items.size();


    // Create a table to store the maximum values
    vector<vector<int>> table(n + 1, vector<int>(capacity + 1, 0));


    // Fill the table using dynamic programming approach
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= capacity; j++) {
            if (items[i - 1].weight <= j) {
                table[i][j] = max(items[i - 1].cost + table[i - 1][j - items[i - 1].weight], table[i - 1][j]);
            } else {
                table[i][j] = table[i - 1][j];
            }
        }
    }


    return table[n][capacity];
}


// Main function
int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;


    vector<Item> items(n);


    cout << "Enter the cost and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << ":\n";
        cout << "Cost: ";
        cin >> items[i].cost;
        cout << "Weight: ";
        cin >> items[i].weight;
    }


    int capacity;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;


    int maxValue = knapsack(capacity, items);


    cout << "Maximum achievable value: " << maxValue << endl;


    return 0;
}
