#include <iostream>
using namespace std;

int num1, num2;

// Take and validate input from the user function
void prompt(int &num1, int &num2) {
    while(true) {
        cout << "Enter two numbers a and b: ";
        cin >> num1 >> num2;
        if (num1 <= 0 || num2 <= 0) {
            cout << "ERROR! Invalid input try again!" << endl;
            continue;
        } else break;
    }
}

// Function to compute GCD(a, b)
int gcd(int a, int b) {
    while(b!=0) { // Use Euclidean Algorithm to find gcd when remainder = 0
        int rem = a%b; // Compute remainder
        a = b; // Set new a to previous b
        b = rem; // Set new b to remainder
    }
    return a;
}

// Function to compute LCM(a, b)
int lcm(int a, int b) {
    int result = (a * b) / gcd(a,b);
    return result;
}

int main() {

    prompt(num1, num2);
    cout << "GCD(" << num1 << ", " << num2 << ") = " << gcd(num1, num2) << endl;
    cout << "LCM(" << num1 << ", " << num2 << ") = " << lcm(num1, num2) << endl;
    
    return 0;
}