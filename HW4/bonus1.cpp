#include <iostream>
using namespace std;

// Function to get and validate array size input
int prompt(char id) {
    int answer;

    while(true) {
        cout << "Enter size of array " << id << ": ";
        cin >> answer;
        if (answer <= 0) {
            cout << "ERROR! Invalid input. Try again!" << endl;
            continue;
        } else break;
    }

    return answer;
}

// Function to enter elements of array
void getArr(int arr[], int size, char id) {
    cout << "Enter elements of array " << id << ": ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

// Function to print array
void printArray(int arr[], int size) {
    for(int i = 0; i<size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to determine and print conclusion of subarray evaluation
void printIsSubarray(char id, bool isSubarray) {
    switch (id) {
    case 'A':
        if (isSubarray) cout << "A is subset of B.";
        else cout << "A is not subset of B.";
        break;
    case 'B':
        if (isSubarray) cout << "B is subset of A.";
        else cout << "B is not subset of A.";
        break;
    default:
        if (isSubarray) cout << "The arrays are subset of one another.";
        else cout << "No array is a subset of the other.";
        break;
    }

    cout << endl;
}

// Function to determine if array is subset
void isSubarray (int arrA[], int sizeA, int arrB[], int sizeB) {
    bool isSubset = false;
    char subset;

    if (sizeA < sizeB) {
        subset = 'A';
        bool flag; // Flag to determine if element is found
        for (int i = 0; i < sizeA; i++) {
            flag = false;
            for (int j = 0; j < sizeB; j++) {
                if (arrA[i] == arrB[j]) { // Check if element is found in arr2
                    flag = true;
                    break;
                }
            }
            if (!flag) { // If element in arr1 is not found, array is not subset
                isSubset = flag;
                break;
            }
        }
        isSubset = flag;
    } else if (sizeB < sizeA) {
        subset = 'B';
        bool flag;
        for (int i = 0; i < sizeB; i++) {
            flag = false;
            for (int j = 0; j < sizeA; j++) {
                if (arrB[i] == arrA[j]) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                isSubset = flag;
                break;
            }
        }
        isSubset = flag;
    } else {
        bool flag;
        for (int i = 0; i < sizeA; i++) {
            flag = false;
            for (int j = 0; j < sizeB; j++) {
                if (arrA[i] == arrB[j]) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                isSubset = flag;
                break;
            }
        }
        isSubset = flag;
    }
    printIsSubarray(subset, isSubset);
}


int main() {

    int sizeA = prompt('A');
    int arrA[sizeA];
    getArr(arrA, sizeA, 'A');

    int sizeB = prompt('B');
    int arrB[sizeB];
    getArr(arrB, sizeB, 'B');

    isSubarray(arrA, sizeA, arrB, sizeB);

    return 0;
}