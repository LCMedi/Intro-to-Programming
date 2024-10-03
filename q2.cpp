#include <iostream>
#include <cmath>
using namespace std;

int runs = 0; //count the number of runs to implement exit

int main() {

    int lb = 0;
    int ub = 0;

    while(true) {
        
        if (runs > 0) {
            char answer;
            cout << "Would you like to continue? [Enter 'Y' for Yes or 'N' for No.]: ";
            cin >> answer;
            if (answer == 'N') break;
        }

        cout << "Enter left bound of the range: ";
        cin >> lb;
        cout << "Enter right bound of the range: ";
        cin >> ub;

        if((lb >= 0) && (ub > lb)) {
            
            cout << "Armstrong numbers found in range [" << lb << "-" << ub << "):" << endl;

            for(int i = lb; i < ub; i++) {

                int sum = 0; //sum of digits
                int n = 0; //n number of digits
                int j = i; //copy of i to count n
                int k = i; //copy of i to calculate sum
                
                while(j != 0) { //count number of digits
                    j /= 10;
                    n++;
                }

                while(k != 0) { //calculate the sum of digits to the power of n
                    int dig = k%10; //last digit of i;
                    k /= 10;
                    sum += pow(dig, n);
                }

                if(i==sum) {
                    cout << i << endl;
                }
            }
        } else {
            cout << "ERROR! Invalid range. Try again." << endl;
            continue;
        }
        runs++;
    }

    return 0;
}