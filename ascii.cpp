#include <string>
#include <iostream>
#include <fstream>

//return a string containing n times the character c
std::string repeat(char c, int n) {
    std::string s = "";
    for (int i = 0; i < n; i++) {
        s += c;
    }
    return s;
}

//return a string containing every character of the alphabet n times
std::string repeatAlphabet(int n) {
    std::string s = "";
    for (char c = 'A'; c <= 'Z'; c++) {
        s += repeat(c, n);
    }
    return s;
}

int main() {
    std::string res = "";
    std::string alphabet = repeatAlphabet(1);
    std::ifstream inputFile;
    inputFile.open("ascii_art_sample_ts1_input.txt");
    
    if (inputFile.is_open()) {
        std::string line;
        int cases = 1;
        //nb of cases to test 
        inputFile >> line;
        int nbCases = stoi(line)+1;

        while (cases < nbCases) {
            std::string letters = alphabet;
            int i = 2;

            //nth character to find
            inputFile >> line;
            int n = stoi(line);

            while (letters.length() < n) {
                letters += repeatAlphabet(i);
                i++;
            }

            res = res + "Case #" + std::to_string(cases) + ": " + letters[n-1] + "\n";

            cases++;
        }

        inputFile.close();
    }

    std::ofstream outputFile;
    outputFile.open("ascii_art_sample_ts1_output.txt");
    if (outputFile.is_open()) {
        outputFile << res;
        outputFile.close();
    }
    
    return 0;
}