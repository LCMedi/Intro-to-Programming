#include <iostream>
using namespace std;

int main() {

    int a, b;

    cout << "Enter a value for number a: ";
    cin >> a;
    
    cout << "Enter a value for number b: ";
    cin >> b;

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    cout << "After swapping values:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}
