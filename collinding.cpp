#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <map>
#include <unordered_set>

int main ()
{
    std::string res = "";
    std::ifstream inputFile;
    inputFile.open("colliding_encoding_sample_ts1_input.txt");
    
    if (inputFile.is_open()) {
        std::string line;
        int cases = 1;
        //nb of cases to test 
        inputFile >> line;
        int nbCases = stoi(line)+1;

        while (cases < nbCases) {            
            bool collinding = false;
            //encryption of every letter
            inputFile >> line;
            char* letters = new char[26];
            int index = 0;
            for (int i = 0; i < line.length(); i++) {
                if (line[i] != ' ') {
                    letters[index] = line[i];
                    index++;
                }
            }

            //number of words to encrypt
            inputFile >> line;
            int nbWords = stoi(line);

            //words to encrypt
            std::string * words = new std::string[nbWords];
            for (int a = 0; a < nbWords; a++) {
                inputFile >> line;
                words[a] = line;
            }

            //encryption
            std::map<char, char> alphabet;
            int l = 0;
            for (char c = 'A'; c <= 'Z'; c++) {
                alphabet[c] = letters[l];
            }

            std::string * encryptedWords = new std::string[nbWords];
            for (int b = 0; b < nbWords; b++) {
                std::string word = "";
                for (int d = 0; d < words[b].length(); d++) {
                    word += alphabet[words[b][d]];
                }
                encryptedWords[b] = word;
            }

            //looking for colliding encoding
            std::unordered_set<std::string> set;
            set.insert(encryptedWords[0]);
            for (int i = 1; i < nbWords; i++) {
                if (set.count(encryptedWords[i])) {
                    collinding = true;
                    break;
                }
            }

            res = res + "Case #" + std::to_string(cases) + ": ";
            if (collinding == true)
                res += "YES\n";
            else
                res += "NO\n";

            delete[] letters;
            delete[] words;
            delete[] encryptedWords;
            cases++;
        }

        inputFile.close();
    }

    std::ofstream outputFile;
    outputFile.open("colliding_encoding_sample_ts1_output.txt");
    if (outputFile.is_open()) {
        outputFile << res;
        outputFile.close();
    }
    
    return 0;
}