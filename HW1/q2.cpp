#include <iostream>
#include <iomanip>
using namespace  std;

int main() {

    int num;
    int reversed_num = 0;
    int sum = 0;

    cout << "Enter a number (1000-9999): ";
    cin >> num;

    for (int i = 0; i < 4; i++) {
        reversed_num = reversed_num * 10 + (num % 10);
        sum += (num % 10);
        num /= 10;
    }

    cout << "Number with reversed digits: " << setw(4) << setfill('0') << reversed_num << endl;
    cout << "The sum of the digits is: " << sum << endl;

    return 0;
}
