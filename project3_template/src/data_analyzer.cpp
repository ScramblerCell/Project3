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


using namespace std;
//prototype functions
void printTitle();
void printVectorContents(vector<double> data);
void printLastElements(string file, vector<double> data, int preSizeVector, int postSizeVector);

int main(){
    
    vector<double> results;
    printTitle();

    //read how many files will be processed
    int NumFilesToRead; 
    cout << "Enter the number of files to read: ";
    cin >> NumFilesToRead;
    cout << endl;

    //take in fileName
    //string ithFileName = "/Users/jonahdowning/AU Coding Projects/COMP2710/Project3/project3_template/src/data.txt";

    string fileToBeProcessed;
    
    for (int i = 1; i <= NumFilesToRead; i++ ) {
    //take in file to be processed
        cout << "Enter the filename for file " << i << ": ";
        cin >> fileToBeProcessed;
    //check file FIXME
        
    //read file
        int preSize = results.size();
        if(read_file(fileToBeProcessed, results)==false) {
            i--;
            continue;
        }
        int postSize = results.size();
        printLastElements(fileToBeProcessed, results, preSize, postSize);

    //print elements in file (for testing purposes, remove afterwards)

        cout << endl;
    }

    //Statistics Section
    cout << "*** Summarized Statistics ***\n" << endl;

    //Sort 

    //print stats
    cout << "Mean: " << find_mean(results) << endl;


    //5. print elements from new vector
    
    //sort cumulativeResults into new file sortedResults
    //printOrderedResults
    
    //////////////////////////////////////
   /*  printTitle(); */
    //read how many files will be processed
    /* int NumFilesToRead; 
    cout << "Enter the number of files to read: ";
    cin >> NumFilesToRead; */

    //take in fileName
    //string ithFileName = "/Users/jonahdowning/AU Coding Projects/COMP2710/Project3/project3_template/src/data.txt";

    /* string ithFileName;
    cout << "Enter the filename for file 1: ";
    cin >> ithFileName;

    //check file
    std::ifstream file (ithFileName);
    vector<double> results;
    string currLine;
    int i = 0;
    while (getline(file, currLine )) {
        results.push_back(stod(currLine));
        i++;
    }
    printVectorContents(results);
    file.close();
 */
    /* For loop 
        1. read file name
        2. print elements in file (for testing purposes, remove afterwards)
        3. write to new vector cumulativeResults
        4. print elements from new vector
    */
    //sort cumulativeResults into new file sortedResults
    //printOrderedResults
}

void printTitle() {
cout<<"\n\n\n*** Welcome to Jonah's Data Analyzer ***\n";
}
void printVectorContents(vector<double> data) {
    for (int i = 0; i < data.size(); i++) {
        cout << data.at(i) << endl;
    }
}
void printLastElements(string file, vector<double> data, int preSizeVector, int postSizeVector) {
    cout << "The list of " << postSizeVector - preSizeVector << " values in file " << file << " is:" << endl; 
    for (int i = preSizeVector; i < postSizeVector;i++) {
        cout << data.at(i) << endl;
    }
    cout << endl;
}
