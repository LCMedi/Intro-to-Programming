#include <iostream>
using namespace std;

// Function to get and validate array size input
int prompt() {
    int answer;

    while(true) {
        cin >> answer;
        if (answer < 0) {
            cout << "ERROR! Invalid input. Try again!" << endl;
            continue;
        } else break;
    }

    return answer;
}

// Function to enter elements of array
void getArr(int arr[], int size, string arrayNum) {
    cout << "Enter elements in " << arrayNum <<  " array: ";
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

// Function to sort array in ascending order using Bubble Sort Algorithm
void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Function to merge two arrays into a single array and order in ascending order
void mergeArray(int arr1[], int arr2[], int arr3[], int size1, int size2) {
    int index = 0;

    // Copy the two arrays into one
    for (int i = 0; i < size1; i++) {
        arr3[index++] = arr1[i];
    }
    for (int j = 0; j < size2; j++) {
        arr3[index++] = arr2[j];
    }

    // Order elements of the array in ascending order
    sortArray(arr3, size1 + size2);
}

int main() {

    cout << "Enter the number of elements in first array: ";
    int size1 = prompt();

    int* arr1 = new int[size1];
    getArr(arr1, size1, "first");

    cout << "Enter the number of elements in second array: ";
    int size2 = prompt();

    int* arr2 = new int[size2];
    getArr(arr2, size2, "second");

    int size3 = size1 + size2;
    int* arr3 = new int[size3];

    mergeArray(arr1, arr2, arr3, size1, size2);
    printArray(arr3, size3);

    // Deallocate memory for arrays
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    return 0;
}