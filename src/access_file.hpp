#ifndef _ACCESS_FILE_H_
#define _ACCESS_FILE_H_

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

void writeVectorContents(fstream& file, vector<double> data);
void writeStatistics(fstream& file, vector<double> data, double mean, double median, double mode);

/**
 * @brief checks if FILEPATH is accessible
 * 
 * @param FILEPATH  string of file path
 * @return true     FILEPATH was accessible
 * @return false    FILEPATH wasn't accessible
 */
bool check_file(string FILEPATH);

void printIllegalContentFound();

/**
 * @brief determines if inputs string is valid number to be evaluated
 * 
 * @param str       string to be evaluated
 * @return true     if string is valid
 * @return false    if string is not valid
 */
bool isValidNumber(const string& str);
/**
 * @brief read file in FILEPATH then parse the file and save its content into vector v
 * 
 * @param FILEPATH  a string of file path
 * @param v         a reference to a vector of double
 * @return true     if FILEPATH is legal
 * @return false    if FILEPATH isn't legal
 */
bool read_file(string FILEPATH, vector<double>& v);

/**
 * @brief write v, mean, median and mode to file in FILEPATH
 * 
 * @param FILEPATH  a string of file path
 * @param v         a sorted vector of double
 * @param mean      a double that is the calculated mean of v
 * @param median    a double that is the calculated median of v
 * @param mode      a double that is the calculated mode of v
 * @return true     writing process was sucessful
 * @return false    writing process wasn't successful
 */
bool write_file(string FILEPATH, vector<double> v, double mean, double median, double mode);

#endif