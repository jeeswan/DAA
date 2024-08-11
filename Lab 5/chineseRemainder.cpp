#include <iostream>
using namespace std;

int findMinX(int num[], int rem[], int k) {
    int x = 1; // Initialize result

    // As per the Chinese remainder theorem,
    // this loop will always break.
    while (true) {
        // Check if remainder of x % num[j] is 
        // rem[j] or not (for all j from 0 to k-1)
        int j;
        for (j = 0; j < k; j++)
            if (x % num[j] != rem[j])
                break;

        // If all remainders matched, we found x
        if (j == k)
            return x;

        // Else try next number
        x++;
    }

    return x;
}

// Driver method
int main() {
    int num[] = {3, 5, 7}; // Updated data
    int rem[] = {1, 4, 6};   // Updated data
    int k = sizeof(num) / sizeof(num[0]);

    cout << "x is " << findMinX(num, rem, k) << endl;
    return 0;
}
