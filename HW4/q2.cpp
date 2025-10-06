#include <iostream>
using namespace std;

// Function to get and validate array size input
int prompt() {
    int answer;

    while(true) {
        cout << "Enter size of array: ";
        cin >> answer;
        if (answer <= 0) {
            cout << "ERROR! Invalid input. Try again!" << endl;
            continue;
        } else break;
    }

    return answer;
}

// Function to enter elements of array
void getArr(int arr[], int size) {
    cout << "Enter elements of array: ";
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

// Function to rotate array by k positions
void rotateArray(int arr[], int size, int k) {
    if (k==0) return; // Exit if no rotation
    for (int i = 0; i < k % size; i++) {
        int previous; // Temporary variable to hold previous term
        for (int j = 0; j < size; j++) {
            if (j==0) { // Handle first term separately
                previous = arr[j];
                arr[j] = arr[size - 1];
            } else {
                int temp = arr[j];
                arr[j] = previous;
                previous = temp;
            }
        }
    }
}

int main() {

    int arr_size = prompt();
    int arr[arr_size];
    int rotations;

    getArr(arr, arr_size);

    cout << "Enter number of rotations: ";
    cin >> rotations;

    rotateArray(arr, arr_size, rotations);
    cout << "Array after rotating " << rotations << " times: ";
    printArray(arr, arr_size);

    return 0;
}