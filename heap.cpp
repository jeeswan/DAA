/*
Theory:
    Heap Sort is a comparison-based sorting algorithm that builds a heap from the input array and repeatedly extracts the maximum 
    (for max heap) or minimum (for min heap) element from the heap and places it at the end of the sorted array.

Complexities:

    Time Complexity:
        Best Case: O(nlog?n)O(nlogn)
        Worst Case: O(nlog?n)O(nlogn) 
        Average Case: O(nlog?n)O(nlogn) 
    Space Complexity:
        O(1)O(1) for in-place sorting.
*/

#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int>& arr, int n, int i, int& total_steps) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }

    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest, total_steps);
    }

    total_steps++;
}

void heapSort(vector<int>& arr, int& total_steps) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i, total_steps);
    }

    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, total_steps);
    }
}

int main() {
    vector<int> arr = {13, 15, 8, 10, 4, 7};
    int total_steps = 0;

    heapSort(arr, total_steps);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Total number of steps: " << total_steps << endl;

    return 0;
}
