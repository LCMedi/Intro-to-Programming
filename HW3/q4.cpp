#include <iostream>
using namespace std;

int rows;

// Take and validate input from the user function
int prompt() {
    int answer;

    while(true) {
        cout << "Enter rows: ";
        cin >> answer;
        if (answer <= 0) {
            cout << "ERROR! Invalid input. Try again!" << endl;
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

// Binomial coefficient formula function
/* int binomialCoefficient(int a, int b) {
    int result = factorialCalc(a) / (factorialCalc(b) * factorialCalc(a - b)); // a choose b formula: a!/b!(a-b)!
    return result;
} */

// Function to calculate triangle's coefficient using recursion
int pascalCoefficients(int col, int row) {
    if (col == 0 || col == row) {
        return 1;
    } else {
        return pascalCoefficients(col - 1, row - 1) + pascalCoefficients(col, row - 1);
    }
}

// Print Pascal Triangle Function
void printTriangle(int rows) {
    for(int i = 0; i < rows; i++) { // Print rows
        for (int k = 0; k < rows - i - 1; k++) { // Print whitespaces in front of coefficients
            cout << " ";
        }
        for(int j = 0; j <= i; j++) { // Print columns
            if(j==0 || j==i) {
                cout << 1 << " ";
            } else {
                cout << pascalCoefficients(j, i) << " ";
                //cout << binomialCoefficient(i, j) << " ";
            }
        }
        cout << endl;
    }
}

int main() {

    rows = prompt();
    printTriangle(rows);

    return 0;
}
