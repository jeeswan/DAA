#include <iostream>
#include <vector>

using namespace std;

void printSolution(vector<int>& subset) {
    cout << "{ ";
    for (int i = 0; i < subset.size(); i++)
        cout << subset[i] << " ";
    cout << "}" << endl;
}

bool subsetSumUtil(vector<int>& nums, int n, int sum, vector<int>& subset) {
    if (sum == 0) {
        printSolution(subset);
        return true;
    }

    if (n == 0)
        return false;

    if (nums[n - 1] > sum)
        return subsetSumUtil(nums, n - 1, sum, subset);

    subset.push_back(nums[n - 1]);
    bool include = subsetSumUtil(nums, n - 1, sum - nums[n - 1], subset);

    subset.pop_back();
    bool exclude = subsetSumUtil(nums, n - 1, sum, subset);

    return include || exclude;
}

void subsetSum(vector<int>& nums, int sum) {
    vector<int> subset;
    if (!subsetSumUtil(nums, nums.size(), sum, subset))
        cout << "No subset with given sum" << endl;
}

int main() {
    vector<int> nums = {3, 34, 4, 12, 5, 2};
    int sum = 9;

    subsetSum(nums, sum);

    return 0;
}
