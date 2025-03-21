#include <iostream>
#include "access_file.hpp"
#include <vector>
using namespace std;

bool check_file(string FILEPATH){
    /* try {
        // Check if the file exists and is a regular file (not a directory or symbolic link)
        return fs::exists(FILEPATH) && fs::is_regular_file(FILEPATH);
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Error checking file: " << e.what() << std::endl;
        return false;
    } */
    
    std::ofstream file ("test1.txt");
    
    
    file.close();
    return true;
}

bool read_file(string FILEPATH, vector<double>& v) {
    ifstream file(FILEPATH);
    string currLine;
    int i = 0;
    while (std::getline(file, currLine))
    {
        v.push_back(stod(currLine));
    }

    file.close();
    return true;
}

bool write_file(string FILEPATH, vector<double> v, double mean, double median, double mode){
    // put your inplementation here
    return true;
}



