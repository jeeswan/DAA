#include <iostream>

using namespace std;

int step = 0; 

// Function to perform sequential search
int sequentialSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        step++; 
        if (arr[i] == key) {
            return i; 
        }
    }
    return -1;
}

int main() {
    int arr[] = {12, 45, 7, 23, 56, 34, 98, 3, 87};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;
    
    cout << "Enter the element to search: ";
    cin >> key;

    int index = sequentialSearch(arr, size, key);

    if (index != -1) {
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    cout << "Number of steps taken for sequential search: " << step << endl;

    return 0;
}

