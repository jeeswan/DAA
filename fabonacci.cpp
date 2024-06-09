#include <iostream>
using namespace std;
void printFibonacci(int n, int a, int b, int& steps) {
    steps++;
    if (n <= 0) {
        return;
    }

    int c = a + b;
    cout << c << " ";
    printFibonacci(n - 1, b, c, steps);
}

int main() {
    int n;
    int steps = 0;
    
    cout << "Enter the number of terms in the Fibonacci series: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Number of terms should be greater than zero.\n";
        return 1;
    }
    
    if (n >= 1) {
        cout << "Fibonacci Series: ";
        cout << "0 "; // First term
    }
    
    if (n >= 2) {
        cout << "1 "; 
    }

    printFibonacci(n - 2, 0, 1, steps); 
    cout << "\nSteps: " << steps << endl;
    
    return 0;
}
