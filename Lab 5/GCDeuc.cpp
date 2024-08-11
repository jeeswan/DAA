#include <iostream>
using namespace std;

// Function to return gcd of a and b
int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

// Driver Code
int main() {
    int a = 30, b = 18;
  
    // Function call
    cout << "GCD(" << a << ", " << b << ") = " << gcd(a, b) << endl;
    a = 12, b = 480;
    cout << "GCD(" << a << ", " << b << ") = " << gcd(a, b) << endl;
    a = 120, b = 11;
    cout << "GCD(" << a << ", " << b << ") = " << gcd(a, b) << endl;

    return 0;
}
