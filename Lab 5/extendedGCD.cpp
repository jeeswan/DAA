#include <iostream>

// Function to implement the extended Euclidean algorithm
int extendedGCD(int a, int b, int &x, int &y) {
    // Base case
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int gcd = extendedGCD(b, a % b, x1, y1);

    // Update x and y using results of the recursive call
    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
}

int main() {
    int a = 161, b = 28, x, y;

    int gcd = extendedGCD(a, b, x, y);

    std::cout << "GCD(" << a << ", " << b << ") = " << gcd << std::endl;
    std::cout << "Linear combination: " << a << " * (" << x << ") + " << b << " * (" << y << ") = " << gcd << std::endl;

    return 0;
}
