#include <iostream>
using namespace std;

int k = 0;
double e = 0;

// Take and validate input from the user function
int prompt() {
    int answer;

    while(true) {
        cout << "Enter the order to approximate e: ";
        cin >> answer;
        if (answer < 1) {
            cout << "ERROR! Invalid input try again!" << endl;
            continue;
        } else break;
    }

    return answer;
}

// Factorial calculator function
int factorialCalc(int num) {
    int result = 1;
    if (num == 0) return result;
    while (num > 0) {
        result *= num;
        num--;
    }
    return result;
}

// Function to approxiamte e using Euler's formula
double eCalc(int order) {
    double num = 1;
    double den;
    double result = 0;
    
    for (int i = 0; i < order; i++) {
        den = factorialCalc(i);
        result += num/den;
    }
    return result;
}

int main() {

    k = prompt();
    e = eCalc(k);
    cout << "Approximate e with order " << k << " is: " << e;

    return 0;
}