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

// Function to find the median of array
double findMedian(int arr[], int size) {
    int mid_index = size / 2;
    sortArray(arr, size); // Sort array in ascending order

    if (size % 2 == 0) { // If even size of array
        return (arr[mid_index-1] + arr[mid_index])/2.0;
    } else { // If odd size of array
        return arr[mid_index];
    }
}

int main() {

    int arr_size = prompt();
    int arr[arr_size];

    getArr(arr, arr_size);
    
    cout << "Median of array is " << findMedian(arr, arr_size) << endl;

    return 0;
}