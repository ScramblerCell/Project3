#include <iostream>
#include "process_vector.hpp"
using namespace std;

void MergeSort(vector<double>& v, int left, int right) {


}

vector<double> merge(vector<double> v1, vector<double> v2){
    // put your inplementation here

}

double find_mean (vector<double> v){
    double sum = 0;
    //iterate through to find sum
    for (int i = 0; i < v.size();i++) {
        sum += v.at(i);
    }
    double mean = sum / v.size();
    return mean;

}

double find_median (vector<double> v){
    // put your inplementation here
}

double find_mode (vector<double> v){
	// put your inplementation here
}