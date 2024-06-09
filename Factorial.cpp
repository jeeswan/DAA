#include <iostream>

using namespace std;

int step = 0; // Global variable to count the number of steps

int fact(int n) {
    step++; // Increment step counter
    if (n == 0) {
        return 1;
    } else {
        return n * fact(n - 1);
    }
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    if (num < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
    } else {
        int result = fact(num);
        cout << "Factorial of " << num << " is " << result << "." << endl;
        cout << "Number of steps taken to complete the calculation: " << step << endl;
    }
    return 0;
}

