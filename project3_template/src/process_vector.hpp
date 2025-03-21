#ifndef _PROCESS_VECTOR_H_
#define _PROCESS_VECTOR_H_

#include <vector>

using namespace std;

/**
 * @brief starts the recursive mergeSort algorithm
 * 
 * @param data  The vector to be sorted.
 * @param left  The leftmost index of the subarray to be sorted.
 * @param right The rightmost index of the subarray to be sorted.
 */
void mergeSort(vector<double>& v, int left, int right);

/**
 * @brief key part of the inductive step within mergeSort method
 * 
 * @param data  The vector containing the subarrays to be merged.
 * @param left  The leftmost index of the first subarray.
 * @param mid   The middle index that divides the two subarrays.
 * @param right The rightmost index of the second subarray.
 */
void merge(vector<double> &data, int left, int mid, int right);


/**
 * @brief finds mean
 * 
 * @param v         vector of doubles
 * @return double   that is the mean of all the doubles in v
 */
double find_mean (vector<double> v);

/**
 * @brief finds middle value in vector; if 2 medians, then take average
 * 
 * @param v         sorted vector to be evaluated
 * @return double   median value
 */
double find_median (vector<double> v);

/**
 * @brief finds most frequent value in vector
 * 
 * @param v         sorted vector to be processed
 * @return double   mode
 */
double find_mode (vector<double> v);

#endif