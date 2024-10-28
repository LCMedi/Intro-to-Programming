#include <iostream>
using namespace std;

int n = 0;

// Take and validate input from the user function
int prompt() {
    int answer;

    while(true) {
        cout << "Enter n: ";
        cin >> answer;
        if (answer < 0) {
            cout << "ERROR! Invalid input try again!" << endl;
            continue;
        } else break;
    }

    return answer;
}

// Recursive function to calculate fibonacci sequence numbers
int fibonacciFunction(int n) {
    if (n >= 2) {
        return fibonacciFunction(n-1) + fibonacciFunction(n-2);
    } else if (n == 1) {
        return 1;
    } else {
        return 0;
    }
}

// Function to print Fibonacci sequence
void printSequence(int n) {
    cout << "Fibonacci Sequence up to F(" << n << "):" << endl;
    for(int i = 0; i <= n; i++) {
        if (n == 0 || i == n) {
            cout << fibonacciFunction(i);
        } else {
            cout << fibonacciFunction(i) << ", ";
        }
    }
}

int main() {

    n = prompt();
    printSequence(n);

    return 0;
}
