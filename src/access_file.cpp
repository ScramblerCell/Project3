#include <iostream>
#include "access_file.hpp"
#include <vector>
#include <regex>
#include <fstream>
using namespace std;

void printVectorContents(std::ostream& out, vector<double> data) {
    for (int i = 0; i < data.size(); i++) {
        out << data.at(i) << " ";
    }
    out<<endl;
}
void printStatistics(std::ostream& out, vector<double> data, double mean, double median, double mode) {
    //print
    out << "The orderely sorted list of " << data.size() << " values is: " << endl;
    printVectorContents(out, data);
    //print stats
    out << "\nThe mean is " << fixed << setprecision(4) << mean << endl;
    out << "The median is " << fixed << setprecision(4) << median << endl;
    out << "The mode is " << fixed << setprecision(4) << mode << endl;
}

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
    fstream file;
    //FIXME: check if file is valid
    file.open(FILEPATH, ios::out);
    if (file.is_open()) {
        printStatistics(file, v, mean, median, mode);
        return true;
    }
    
    return false;
}




