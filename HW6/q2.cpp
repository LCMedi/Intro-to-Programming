#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
using namespace std;
const int MAXWORDS = 1000;

struct WordEntry {
    string word;
    int frequency;
};

string normalizeWord(string word) {
    string normalizedWord;
    for (char letter : word) {
        if (isalpha(letter)) normalizedWord += tolower(letter);
    }
    return normalizedWord;
}

void processWords(WordEntry words[], ifstream &input, int &count) {
    string currentWord;

    while(input >> currentWord) {
        bool flag = false;
        currentWord = normalizeWord(currentWord);

        if (currentWord.empty()) {
            continue;
        }

        for (int i = 0; i < count; i++) {
            if(words[i].word == currentWord) {
                words[i].frequency++;
                flag = true;
                break;
            }
        }

        if (!flag) {
            if (count >= MAXWORDS) {
                cout << "Limit has been reached. Program will not read further words." << endl;
                return;
            }
            words[count].word = currentWord;
            words[count].frequency = 1;
            count++;
        }

    }
}

void writeToFile(const WordEntry words[], string filename, ofstream &output, int count) {
    for (int i = 0; i < count; i++) {
        output << words[i].word << ": " << words[i].frequency << endl; 
    }
    cout << "Word frequencies have been written to " << filename << endl;
}

int main() {

    string iFilename;
    string oFilename;

    ifstream inputFile;

    cout << "Enter the input filename: ";
    cin >> iFilename;

    inputFile.open(iFilename);

    if (!inputFile) {
        cout << "Error! Could not open file with given file name." << iFilename << endl;
        return 1;
    }

    WordEntry words[MAXWORDS];
    int count = 0;
    processWords(words, inputFile, count);

    cout << "Enter the output filename: ";
    cin >> oFilename;

    ofstream outputFile(oFilename);

    writeToFile(words, oFilename, outputFile, count);

    inputFile.close();
    outputFile.close();

    return 0;
}