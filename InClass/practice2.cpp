#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {

    int value, down_payment, num_months;
    double apr, principle, monthly_payment, r;

    cout << "Enter value of the car you want to purchase: ";
    cin >> value;

    cout << "Enter your down payment: ";
    cin >> down_payment;

    cout << "Enter the APR of your loan (%): ";
    cin >> apr;

    cout << "Enter the length of your loan (in months): ";
    cin >> num_months;

    principle = value - down_payment;
    r = (apr/100) / 12;

    double numerator = principle*r*pow(1+r,num_months);
    double denominator = pow(1+r,num_months) - 1;

    monthly_payment = numerator / denominator;
    double total = monthly_payment*num_months + down_payment;
    
    cout << fixed << setprecision(2);
    cout << "Your monthly payment is: " << monthly_payment << endl;
    cout << "Your total payment is: " << total << endl;

    return 0;
}
