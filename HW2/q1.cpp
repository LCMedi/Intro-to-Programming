#include <iostream>
using namespace std;

int runs = 0; //count the number of runs to implement exit

int main() {

    int count = 0;
    int lb = 0;
    int ub = 0;

    while (true) {
        
        if (runs > 0) {
            char answer;
            cout << "Would you like to continue? [Enter 'Y' for Yes or 'N' for No.]: ";
            cin >> answer;
            if (answer == 'N') break;
        }
        
        cout << "Enter left side of the range: ";
        cin >> lb;
        cout << "Enter right side of the range: ";
        cin >> ub;
        
        if ((lb <= 0) || (ub <= lb)) {
            cout << "Error! Invalid range. Try again." << endl;
            continue;
        } else {
            for (int i = lb; i < ub; i++) {
                bool is_prime = true;
                if (i <= 1) continue;
                for (int j = 2; j*j <= i; j++) {
                    if (i%j==0) {
                        is_prime = false;
                        break;
                    }
                }
                if (is_prime) {
                    cout << i << endl;
                    count++;
                }
            }
            cout << "There are " << count << " prime numbers within the given range." << endl;
        }
        count = 0;
        runs++;
    }

    return 0;
}
