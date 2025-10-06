#include <iostream>
using namespace std;

// Function to get and validate array size input
void prompt(int &rows, int &cols, char id) {
    while(true) {
        cout << "Enter " << id << "'s" << " number of rows and columns: ";
        cin >> rows >> cols;
        if (rows <= 0 || cols <= 0) {
            cout << "ERROR! Invalid input. Try again!" << endl;
            continue;
        } else break;
    }
}

// Function to enter elements of 2D array
void get2dArr(int* arr[], int rows, int cols, char id) {
    cout << "Enter elements of " << id << ": " << endl;
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

// Function to calculate dot product of two matrices
int** calculateDot(int* arr1[], int* arr2[], int m, int n1, int n2, int p) {
    // Check for error in dimensions
    if(n1!=n2) {
        cout << "Error: Cannot compute product with given dimensions." << endl;
        return NULL;
    }
    // Declare and allocate memory for matrix
    int** arr3 = new int*[m];
    for(int i = 0; i < m; i++) {
        arr3[i] = new int[p]();
    }
    // Calculate Dot Product
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < p; j++) {
            for(int k = 0; k < n1; k++) {
                arr3[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    return arr3;
}

void deallocateMemory(int* arr[], int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

int main() {

    int rows_A,rows_B,cols_A,cols_B;

    prompt(rows_A,cols_A,'A');
    
    // Allocate memory for matrix A
    int** matrix_A = new int*[rows_A];
    for (int i = 0; i < rows_A; i++) {
        matrix_A[i] = new int[cols_A];
    }

    get2dArr(matrix_A, rows_A, cols_A, 'A');

    prompt(rows_B,cols_B,'B');
    
    // Allocate memory for matrix B
    int** matrix_B = new int*[rows_B];
    for (int i = 0; i < rows_B; i++) {
        matrix_B[i] = new int[cols_B];
    }

    get2dArr(matrix_B, rows_B, cols_B, 'B');

    cout << "Matrix A is: " << endl;
    print2dArray(matrix_A, rows_A, cols_A);

    cout << "Matrix B is: " << endl;
    print2dArray(matrix_B, rows_B, cols_B);

    int** matrix_C;
    int rows_C = rows_A;
    int cols_C = cols_B;

    matrix_C = calculateDot(matrix_A, matrix_B, rows_A, cols_A, rows_B, cols_B);
    if (matrix_C != NULL) {
        cout << "The product of A and B is: " << endl;
        print2dArray(matrix_C, rows_C, cols_C);
        deallocateMemory(matrix_C,rows_C);
    }

    deallocateMemory(matrix_A, rows_A);
    deallocateMemory(matrix_B, rows_B);

    return 0;
}