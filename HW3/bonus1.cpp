#include <iostream>
#include <cmath>
using namespace std;

int value = 0;
int downPayment = 0;
int principle;
double monPayment;
int numPayments;

double calculateF(double r) { // Function to calculate f(r)
    double num = principle * r * pow(1+r, numPayments);
    double den = pow(1+r, numPayments) - 1;
    double result = num/den - monPayment;
    return result;
}

double calculateApr(double a = 1e-9, double b = 1.0, int maxIters = 10000) {
    double c = 0;
    int iters = 0; // Number of iterations

    while((fabs(a-b) > 1e-9) && (iters < maxIters)) {
        c = (a+b)/2; // Calculate midpoint

        if (fabs(calculateF(c)) < 1e-9) { // Check if c is the root
            return c * 100;
        } else if (calculateF(c) * calculateF(a) < 0) {
            b = c;
        } else {
            a = c;
        }
        iters++;
    }

    return c * 100;
}

int main() {

    cout << "Enter the value of your car: ";
    cin >> value;
    cout << "Enter your down payment: ";
    cin >> downPayment;
    cout << "Enter your monthly payment: ";
    cin >> monPayment;
    cout << "Enter the number of payments: ";
    cin >> numPayments;
    
    principle = value - downPayment;

    cout << "Your estimated APR (percentage) is: " << calculateApr() << endl;

    return 0;
}
