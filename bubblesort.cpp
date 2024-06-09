#include <iostream>

#define SIZE 10

using namespace std;

int step = 0; // Global variable to count the number of steps

void bubbleSort(int arr[], int N) {
    for (int pass = 0; pass < N - 1; pass++) {
        for (int i = 0; i < N - pass - 1; i++) {
            step++; // Increment step counter for each comparison
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                step++; // Increment step counter for each swap
            }
        }
    }
}

void printArray(int arr[], int N) {
    cout << "Sorted array in ascending order:" << endl;
    for (int i = 0; i < N; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

int main() {
    int arr[SIZE], N;
    cout << "Enter the size of the array: ";
    cin >> N;
    
    if (N > SIZE) {
        cout << "Size exceeds the defined limit." << endl;
        return 1;
    }

    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    bubbleSort(arr, N);
    printArray(arr, N);

    cout << "Number of steps taken to complete the sorting: " << step << endl;

    return 0;
}
