#include <iostream>
#include "access_file.hpp"
#include <vector>
#include <regex>
#include <fstream>
using namespace std;

void writeVectorContents(fstream& file, vector<double> data) {
    for (std::size_t i = 0; i < data.size(); i++) {
        file << data.at(i) << ",";
    }
    file <<endl;
}
void writeStatistics(fstream& file, vector<double> data, double mean, double median, double mode) {
    //print
    file << "The orderely sorted list of " << data.size() << " values is: " << endl;
    writeVectorContents(file, data);
    //print stats
    file << "\nmean," << fixed << setprecision(4) << mean + .0005 << endl;
    file << "median," << fixed << setprecision(4) << median + .0005 << endl;
    file << "mode," << fixed << setprecision(4) << mode + .00005;
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

    while (getline(file, currLine)) {
        if (!isValidNumber(currLine)) {
            printIllegalContentFound();
            file.close();
            cout << "true" << endl;
            return false;
        }

        try {
            fileData.push_back(stod(currLine));
        } catch (const invalid_argument& e) {
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
    for (std::size_t  i = 0; i < fileData.size(); i++) {
        v.push_back(fileData.at(i));
    }

    file.close();
    return true;
}

bool write_file(string FILEPATH, vector<double> v, double mean, double median, double mode){
    fstream file;
    //only continue if accessible
    file.open(FILEPATH, ios::out);
    if (file.is_open()) {
        writeStatistics(file, v, mean, median, mode);
        cout << "*** File " << FILEPATH << " has been written to disk ***" << endl; 
        return true;
    }
    
    return false;
}


