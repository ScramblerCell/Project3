#ifndef _PROCESS_VECTOR_H_
#define _PROCESS_VECTOR_H_

#include <vector>

using namespace std;

/*
function name: MergeSort
arguements:
    v: a reference of a vector of double
purpose: this function sort v in an accending order
*/
void MergeSort(vector<double>& v, int left, int right);

/*
function name: merge
arguements:
    v1: a vector of double
    v2: a vector of double
return value: a vector of double that is the combination of v1 and v2
*/

/**
 * @brief 
 * 
 * @param v1 
 * @param v2 
 * @return vector<double> 
 */
vector<double> merge(vector<double> v1, vector<double> v2);


/**
 * @brief finds mean
 * 
 * @param v     vector of doubles
 * @return double  that is the mean of all the doubles in v
 */
double find_mean (vector<double> v);

/*
function name: find_median
arguements:
    v: a vector of double
return value: a double that is the median of all the doubles in v
*/
double find_median (vector<double> v);
/*
function name: find_mode
arguements:
    v: a vector of double
return value: a double that is the mode of all the doubles in v
*/
double find_mode (vector<double> v);

#endif