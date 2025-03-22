/**
 * data_analyzer.cpp
 * Name: Jonah Downing
 * Auburn UserID: jmd0178
 * Instructions; cd /home/u2/jmd0178/COMP2710/Project3; make;./bin/main
 * Additional Help
 *  - ChatGPT
    - does the .git folder hold all commit history?
    - what does this error mean? Undefined symbols for architecture arm64:
    "check_file(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>)", referenced from:
    _main in data_analyzer-f7e57e.o
    ld: symbol(s) not found for architecture arm64
    clang: error: linker command failed with exit code 1 (use -v to see invocation)
    - what are potential reasons that i’d get this error
    - what does this meanclang: warning: treating 'c-header' input as 'c++-header' when in C++ mode, this behavior is deprecated [-Wdeprecated]
    - what about this line?zsh: permission denied: /Users/jonahdowning/AU Coding Projects/COMP2710/Project3/project3_template/src/access_file
    - why would i get this error:
        
        access_file.cpp:6:21: error: expected namespace name
        namespace fs = std::filesystem;
        ~~~~~^
        
    - how do i ensure vs code compiles with c++ 17
    - is this right?
        
        Apple clang version 15.0.0 (clang-1500.3.9.4)
        Target: arm64-apple-darwin24.3.0
        Thread model: posix
        
    - i dont understand why whenever i press the debug and run button on vs code it builds with errors, but i can compile in the terminal without errors
        
        Undefined symbols for architecture arm64:
        "check_file(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>> const&)", referenced from:
        _main in data_analyzer-b49d5d.o
        ld: symbol(s) not found for architecture arm64
        clang: error: linker command failed with exit code 1 (use -v to see invocation)
        
        Build finished with error(s).
        
    - why did i get  namespace "std" has no member "getLine"
    - getline vs getLine
    - what type of error would result in stod(string) not working
    - stod seems to be too lenient with inputs what can i use instaed
    - whats regex
    - what are a few different strategies to find the mode in a vector
    - why did i get this
        
        process_vector.cpp:84:5: error: no template named 'map'
        map<double,double> elementFrequency;
        
    - 
- Googled
    - What is a vector in cpp
- “**C++ Files**”, “C++ Vectors” , “Maps ”by W3 Schools @https://www.w3schools.com/cpp/cpp_files.asp
- https://www.studyplan.dev/pro-cpp/file-system
- [https://www.studyplan.dev/pro-cpp/file-system#Directory Entry](https://www.studyplan.dev/pro-cpp/file-system#Directory%20Entry)
- https://www.geeksforgeeks.org/merge-sort/
- https://cplusplus.com/reference/ostream/ostream/ostream/
- YT
    - https://www.youtube.com/watch?v=ie282UTAGxg
    - https://www.youtube.com/watch?v=47sZhrJ1USY
    - https://www.youtube.com/watch?v=XJhIJ6J5obY
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

