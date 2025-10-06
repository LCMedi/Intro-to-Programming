#include <iostream>
#include <cstring>
using namespace std;

// Function to print array
void printString(char arr[]) {
    int i = 0;
    while (arr[i] != '\0' && arr[i] != '\n') {
        cout << arr[i];
        i++;
    }
    cout << endl;
}

// Function to reverse words in a sentence
void reverseSentence(char arr[]) {
    int size = strlen(arr);
    char rev_arr[size+1] = "";
    char temp[size+1] = "";
    int temp_index = 0;
    for (int i = size-1; i >= 0; i--) { // Loop backwards through sentence
        if(isspace(arr[i]) || i == 0) {
            int start = (i == 0) ? i : i + 1; // Save start of word
            temp_index = 0;
            for (int j = start; j < size && !isspace(arr[j]); j++) { // Copy word from start to end
                temp[temp_index++] = arr[j];
            }
            temp[temp_index] = '\0';

            strcat(rev_arr, temp);
            strcat(rev_arr, " ");
        }
    }
    int last = strlen(rev_arr);

    if (last > 0 && rev_arr[last - 1] == ' ') {
        rev_arr[last - 1] = '\0';
    }
    printString(rev_arr);
    }


int main() {

    char sentence[1001];

    cout << "Enter a sentence: ";
    cin.getline(sentence, 1001);
    cout << "Reversed words in sentence: ";
    reverseSentence(sentence);

    return 0;
}