/**
 * data_analyzer.cpp
 * Name: Jonah Downing
 * Auburn UserID: jmd0178
 * Instructions; [cd into project_Downing_jmd1078]; make;./bin/main
 * Additional Help
 *  - ChatGPT
 *      - 
 */
#include "access_file.hpp"
#include "process_vector.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <iomanip>


using namespace std;
//prototype functions
void printTitle();
void printStatistics(vector<double> data, double mean, double median, double mode);
void printVectorContents(vector<double> data);
void printLastElements( string file, vector<double> data, int preSizeVector, int postSizeVector);

int main(){
    vector<double> results;
    string fileToBeProcessed;
    
    printTitle();

    //read how many files will be processed
    int NumFilesToRead; 
    cout << "Enter the number of files to read: ";
    cin >> NumFilesToRead;
    cout << endl;
    
    //read and process the files
    for (int i = 1; i <= NumFilesToRead; i++ ) {
    //take in file to be processed
        cout << "Enter the filename for file " << i << ": ";
        cin >> fileToBeProcessed;
        
    //read file
        int preSize = results.size();
        if(!(check_file(fileToBeProcessed)) ||  !(read_file(fileToBeProcessed, results))) {
            i--;
            continue;
        }
        int postSize = results.size();
        printLastElements(fileToBeProcessed, results, preSize, postSize);
        cout << endl;
    }
    
    //Sort 
    mergeSort(results, 0, results.size()-1);

    //Statistics Section
    cout << "*** Summarized Statistics ***\n" << endl;
    printStatistics(results, find_mean(results), find_median(results),find_mode(results));
    //write to CSV file
    string csvFilename;
    cout << "\n\nEnter the output filename to save: ";
    cin >> csvFilename;
    //input validation
    while (!check_file(csvFilename)) {
        cout << "Enter the output filename to save: ";
        cin >> csvFilename;
    }
    cout << "\n" << endl;

    write_file(csvFilename, results, find_mean(results), find_median(results),find_mode(results));

    cout << "*** Goodbye. ***" << endl;
}

void printTitle() {
cout<<"\n\n\n*** Welcome to Jonah's Data Analyzer ***\n";
}

void printLastElements( string file, vector<double> data, int preSizeVector, int postSizeVector) {
    cout << "The list of " << postSizeVector - preSizeVector << " values in file " << file << " is:" << endl; 
    for (int i = preSizeVector; i < postSizeVector;i++) {
        cout << data.at(i) << endl;
    }
    cout << endl;
}
void printVectorContents(vector<double> data) {
    for (std::size_t i = 0; i < data.size(); i++) {
        cout << data.at(i) << " ";
    }
    cout<<endl;
}



void printStatistics(vector<double> data, double mean, double median, double mode) {
    //print
    cout << "The orderely sorted list of " << data.size() << " values is: " << endl;
    printVectorContents(data);
    //print stats
    cout << "\nThe mean is " << fixed << setprecision(4) << mean + .0005 << endl;
    cout << "The median is " << fixed << setprecision(4) << median + .0005 << endl;
    cout << "The mode is " << fixed << setprecision(4) << mode + .0005;
}

