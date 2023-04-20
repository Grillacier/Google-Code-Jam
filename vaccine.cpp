#include <string>
#include <iostream>
#include <fstream>

std::string vaccination() {
    std::string res = "";
    std::ifstream inputFile;
    inputFile.open("immunization_operation_sample_ts1_input.txt");

    if (inputFile.is_open()) {
        std::string line;
        int cases = 1;
        //nb of cases to test 
        inputFile >> line;
        int nbCases = std::stoi(line)+1;

        while (cases < nbCases) {
            int pos = 0;

            //nb of vaccinations and nb of move commands
            inputFile >> line;
            int v = std::stoi(std::string(1, line[0]));
            int m = std::stoi(std::string(1, line[line.length()-1]));

            //locations to pick up vaccines
            inputFile >> line;
            int * pickup = new int[v];
            int index = 0;
            std::string nb = "";
            for (int i = 0; i < line.length(); i++) {
                if (line[i] != ' ') {
                    nb += line[i];
                }
                std::cout << nb << std::endl;
                pickup[index] = std::stoi(nb);
                index++;
                nb = "";
            }

            //boolean array to check if a vaccine has been picked up
            bool * picked = new bool[v];
            for (int i = 0; i < v; i++) {
                picked[i] = false;
            }

            //locations to deliver vaccines
            inputFile >> line;
            int * delivery = new int[v];
            index = 0;
            for (int i = 0; i < line.length(); i++) {
                if (line[i] != ' ') {
                    nb += line[i];
                }
                std::cout << nb << std::endl;
                delivery[index] = std::stoi(nb);
                index++;
                nb = "";
            }

            //boolean array to check if a vaccine has been delivered
            bool * delivered = new bool[v];
            for (int i = 0; i < v; i++) {
                delivered[i] = false;
            }

            //locations to move to
            inputFile >> line;
            int * move = new int[m];
            index = 0;
            for (int i = 0; i < line.length(); i++) {
                if (line[i] != ' ') {
                    nb += line[i];
                }
                std::cout << nb << std::endl;
                move[index] = std::stoi(nb);
                index++;
                nb = "";
            }

            //number of vaccines delivered at each move
            int * vaccines = new int[m];
            for (int i = 0; i < m; i++) {
                vaccines[i] = 0;
            }

            //moving the robot
            for (int i = 0; i < m; i++) {
                pos += move[i];
                for (int j = 0; j < v; j++) {
                    if (pos >= pickup[j]) {
                        picked[j] = true;
                        if (pos >= delivery[j]) {
                            delivered[j] = true;
                            vaccines[i]++;
                        }
                    }
                }
            }

            res = res + "Case #" + std::to_string(cases) + ": ";
            for (int i = 0; i < m; i++) {
                res = res + std::to_string(vaccines[i]) + " ";
            }
            res += '\n';

            cases++;
        }

        inputFile.close();
    }

    std::ofstream outputFile;
    outputFile.open("immunization_operation_sample_ts1_output.txt");
    if (outputFile.is_open()) {
        outputFile << res;
        outputFile.close();
    }
    
    return res;
}

int main() {
    vaccination();
}