#include <iostream>
#include <cstring>
using namespace std;

// Function to enter elements of array
void getArr(int arr[], int size) {
    cout << "Enter elements of array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

// Function to get the size of a cstring
int getSize(char numStr[]) {
   return strlen(numStr);
}

// Function to print array
void printArray(int arr[], int size) {
    for(int i = 0; i<size; i++) {
        cout << arr[i];
    }
    cout << endl;
}

// Function to convert number as cstring to int array and reverse it
void charToInt(char num[], int digits[], int size) {
    for(int i = 0; i < size; i++) {
        digits[i] = num[size - 1 - i] - '0';
    }
}

// Function to multiply two large numbers
int* multiplyLargeNumbers(int* num1, int* num2, int size1, int size2) {
    int size3 = size1 + size2;
    int* num3 = new int[size3] {0};
    for(int i = 0; i < size1; i++) {
        for(int j = 0; j < size2; j++) {
            int product = num1[i] * num2[j];
            num3[i+j] += product;
            num3[i+j+1] += num3[i+j]/10; // Handle carry
            num3[i+j] %= 10; // Reduce product + carry at current position
        }
    }
    return num3;
}

// Function to print large number int arrays taking into account leading zeros
void printLargeNumber(int* num, int size) {
    int index = size - 1;
    while(index>=0 && num[index]==0) {
        index--;
    }

    if (index == -1) {
        cout << "0";
    } else {
        for (int i = index; i >= 0; i--) {
            cout << num[i];
        }
    }
    cout << endl;
}

int main() {

    char* num1 = new char[101];
    char* num2 = new char[101];

    cout << "Enter first large number: ";
    cin.getline(num1,101);

    cout << "Enter second large number: ";
    cin.getline(num2, 101);

    int size1 = getSize(num1);
    int size2 = getSize(num2);

    int* digits1 = new int[size1];
    int* digits2 = new int[size2];

    charToInt(num1, digits1, size1);
    charToInt(num2, digits2, size2);

    
    int* product = multiplyLargeNumbers(digits1, digits2, size1, size2);
    int product_size = size1 + size2;

    printLargeNumber(product, product_size);

    delete[] num1;
    delete[] num2;
    delete[] digits1;
    delete[] digits2;
    delete[] product;

    return 0;
}