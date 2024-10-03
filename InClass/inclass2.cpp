#include <iostream>
#include <cmath>
using namespace std;

int order = 0;

double sigma(int k) {
    double sum = 0;
    for (int i = 1; i <= k; i++) {
        double num = pow((-1),i+1);
        double den = 2*i - 1;
        sum += (num/den);
    }
    return sum * 4;
}

int main() {

    cout << "Enter the order you want to approximate PI: ";
    cin >> order;

    while (order <= 0) {
        cout << "ERROR: invalid order! try again!" << endl;

        cout << "Enter the order you want to approximate PI: ";
        cin >> order;
    }

    cout << "Approximate PI with order " << order << " is: " << sigma(order);

    return 0;
}