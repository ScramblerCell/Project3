#include <iostream>
#include "access_file.hpp"
#include <vector>
#include <regex>
using namespace std;

bool check_file(string FILEPATH){
    ifstream file;
    file.open(FILEPATH);
    if (file.is_open()) {
        file.close();
        return true;
    }
    else {
        cout << "File not found. Please try again.\n" << endl;
        return false;

    }
    

    
    
}

bool isValidNumber(const string& str) {
    regex validNumberPattern("^-?\\d+(\\.\\d+)?([eE][-+]?\\d+)?$");
    return regex_match(str, validNumberPattern);
}

void printIllegalContentFound() {
    cout << "Not an input file. Illegal content/structure detected. Please try again.\n" << endl;
}

bool read_file(string FILEPATH, vector<double>& v) {
    ifstream file(FILEPATH);
    string currLine;
    vector<double> fileData;

    while (std::getline(file, currLine)) {
        if (!isValidNumber(currLine)) {
            printIllegalContentFound();
            file.close();
            return false;
        }

        try {
            fileData.push_back(stod(currLine));
        } catch (const std::invalid_argument& e) {
            printIllegalContentFound();
            file.close();
            return false;
        }
    }
    if (fileData.size() == 0) {
        printIllegalContentFound();
        file.close();
        return false;
    }
    //add fileData to v
    for (int i = 0; i < fileData.size(); i++) {
        v.push_back(fileData.at(i));
    }

    file.close();
    return true;
}

bool write_file(string FILEPATH, vector<double> v, double mean, double median, double mode){
    // put your inplementation here
    return true;
}




