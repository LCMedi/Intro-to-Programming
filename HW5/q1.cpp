#include <iostream>
using namespace std;

int rows, cols;

// Function to get and validate array size input
void prompt(int &rows, int &cols) {
    while(true) {
        cout << "Enter the number of rows and columns: ";
        cin >> rows >> cols;
        if (rows <= 0 || cols <= 0) {
            cout << "ERROR! Invalid input. Try again!" << endl;
            continue;
        } else break;
    }
}

// Function to enter elements of 2D array
void get2dArr(int* arr[], int rows, int cols) {
    cout << "Enter elements of the matrix: " << endl;
    for (int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }
}

// Function to print 2D array
void print2dArray(int* arr[], int rows, int cols) {
    cout << "[";
    for(int i = 0; i < rows; i++) {
        (i!=0) ? cout << " [" : cout << "[";
        for(int j = 0; j < cols; j++) {
            (j==cols-1) ? cout << arr[i][j] : cout << arr[i][j] << ", ";
        }
        (i==rows-1) ? cout << "]" : cout << "]," << endl;
    }
    cout << "]" << endl;
}

// Function to transpose 2D array
void flipArray(int* arr[], int* rev_arr[], int rows, int cols) {
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            rev_arr[i][j] = arr[j][i];
        }
    }
}

int main() {

    prompt(rows,cols);
    
    // Allocate memory for the original array
    int** arr = new int*[rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }

    get2dArr(arr, rows, cols);
    cout << "Original matrix:" << endl;
    print2dArray(arr, rows, cols);

    // Allocate memory for the reversed array
    int** rev_arr = new int*[cols];
    for (int i = 0; i < cols; i++) {
        rev_arr[i] = new int[rows];
    }

    flipArray(arr, rev_arr, rows, cols);

    cout << "Transposed matrix:" << endl;
    print2dArray(rev_arr, cols, rows);

    // Deallocate Memory for both arrays
    for(int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    for(int i = 0; i < rows; i++) {
        delete[] rev_arr[i];
    }
    delete[] rev_arr;

    return 0;
}