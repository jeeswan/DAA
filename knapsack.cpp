/*Theory:
The Knapsack problem is a classic optimization problem that seeks to maximize the value of items selected for inclusion in a
 knapsack, given a limited capacity.

Time Complexity:

    Best Case: O(2n)O(2n) where nn is the number of items. This occurs when the optimal solution is found early during the search.
    Worst Case: O(2n)O(2n) where nn is the number of items. This occurs when all possible combinations need to be considered.
    Average Case: O(2n)O(2n) where nn is the number of items.

Space Complexity:

    O(n)O(n) for recursive stack space due to the backtracking algorithm.
*/

#include <iostream>
using namespace std;

int knapsack(int W, int wt[], int val[], int n, int& steps) {
    int dp[n + 1][W + 1];
    steps++;

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            steps++;
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][W];
}

int main() {
    int val[] = {60, 100, 120, 200};
    int wt[] = {10, 20, 30, 40};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    int steps = 0;

    cout << "Max value in knapsack: " << knapsack(W, wt, val, n, steps) << endl;
    cout << "Number of steps taken: " << steps << endl;

    return 0;
}

