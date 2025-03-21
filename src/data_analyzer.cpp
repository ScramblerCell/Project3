/**
 * data_analyzer.cpp
 * Name: Jonah Downing
 * Auburn UserID: jmd0178
 * Instructions; [cd to file]; [compile and run executable]
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
void printVectorContents(vector<double> data);
void printLastElements(string file, vector<double> data, int preSizeVector, int postSizeVector);

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
    //check file FIXME
        
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

    //Statistics Section
    cout << "*** Summarized Statistics ***\n" << endl;

    //Sort 
    mergeSort(results, 0, results.size()-1);
    //print
    cout << "The orderely sorted list of " << results.size() << " values is: " << endl;
    printVectorContents(results);
    //print stats
    cout << "The mean is " << fixed << setprecision(4) << find_mean(results) << endl;
    cout << "The median is " << fixed << setprecision(4) << find_median(results) << endl;
    cout << "The mode is " << fixed << setprecision(4) << find_mode(results) << endl;

    cout << "\n*** Goodbye. ***" << endl;
}

void printTitle() {
cout<<"\n\n\n*** Welcome to Jonah's Data Analyzer ***\n";
}
void printVectorContents(vector<double> data) {
    for (int i = 0; i < data.size(); i++) {
        cout << data.at(i) << " ";
    }
    cout << "\n" <<endl;
}
void printLastElements(string file, vector<double> data, int preSizeVector, int postSizeVector) {
    cout << "The list of " << postSizeVector - preSizeVector << " values in file " << file << " is:" << endl; 
    for (int i = preSizeVector; i < postSizeVector;i++) {
        cout << data.at(i) << endl;
    }
    cout << endl;
}
