#include <iostream>
using namespace std;

int gcdExtended(int a, int b, int* x, int* y, int* steps) {
    (*steps)++; // Increment step counter

    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }

    int x1, y1; 
    int gcd = gcdExtended(b % a, a, &x1, &y1, steps);
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

int main() {
    int x, y, a, b;
    int steps = 0; // Initialize step counter
    cout << "Enter two numbers: ";
    cin >> a >> b;
    int g = gcdExtended(a, b, &x, &y, &steps);
    cout << "gcd(" << a << ", " << b << ") = " << g << ", steps = " << steps << endl;
    return 0;
}
