#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an item
struct Item {
    float weight;
    int value;
    
    // Constructor for easier initialization
    Item(float w, int v) : weight(w), value(v) {}
};

// Recursive function to solve knapsack problem using backtracking
void knapsackBacktracking(vector<Item>& items, int W, int n, int currentIndex, int currentProfit, int currentWeight, int& maxProfit) {
    // If we have considered all items
    if (currentIndex == n) {
        // Update maximum profit if current profit is greater
        if (currentWeight <= W) {
            maxProfit = max(maxProfit, currentProfit);
        }
        return;
    }

    // Include the current item
    if (currentWeight + items[currentIndex].weight <= W) {
        knapsackBacktracking(items, W, n, currentIndex + 1, 
                             currentProfit + items[currentIndex].value, 
                             currentWeight + items[currentIndex].weight, 
                             maxProfit);
    }

    // Exclude the current item
    knapsackBacktracking(items, W, n, currentIndex + 1, currentProfit, currentWeight, maxProfit);
}

// Driver code
int main() {
    // Create a vector of items with updated values
    vector<Item> items;
    items.push_back(Item(1.5, 60));
    items.push_back(Item(2.3, 70));
    items.push_back(Item(3.1, 80));
    items.push_back(Item(4.0, 90));
    items.push_back(Item(2.7, 100));

    int W = 8; // Updated weight of knapsack

    int maxProfit = 0;
    knapsackBacktracking(items, W, items.size(), 0, 0, 0, maxProfit);

    cout << "Maximum possible profit = " << maxProfit << endl;

    return 0;
}
