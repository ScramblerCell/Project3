#include <iostream>
#include "process_vector.hpp"
using namespace std;

void merge(vector<double> &data, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    //Copy data to temp vectors L[] and R[]
    vector<double> L(n1), R(n2);
    for (int i = 0; i < n1; i++){
        L[i] = data[left + i];
    }
    for (int j = 0; j < n2; j++){
        R[j] = data[mid + 1 + j];
    }

    int i = 0, j = 0;
    int k = left;

    //Merge the temp vectors back into data[left..right]
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j]) {
            data[k] = L[i];
            i++;
        }
        else {
            data[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[],
    while (i < n1) {
        data[k] = L[i];
        i++;
        k++;
    }

    //Copy the remaining elements of R[],
    while (j < n2) {
        data[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<double> &data, int left, int right){
    //base case
    if (left >= right){
        return;
    }
    //inductive step
    int mid = left + (right - left) / 2;
    mergeSort(data, left, mid);
    mergeSort(data, mid + 1, right);
    merge(data, left, mid, right);
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
    int size = v.size();
    if ((size % 2) == 1) {
        return v[size/2];
    }
    else {
        return (v[size/2] + v[size/2 - 1]) / 2.0;
    }
}

double find_mode (vector<double> v){
    int size = v.size();
    //initialize mode
    double mode = v[0];
    int currCount = 1;
    int maxCount = 1;

    for (int i = 1; i < size; ++i) {
        if (v[i] == v[i-1]) {
            ++currCount;
        }
        else {
            //check if count of the prev element is larger than max count
            if (currCount > maxCount) {
                maxCount = currCount;
                mode = v[i-1];
            }
            //reset for new element
            currCount = 1;
        }
    }
    //check last element
    if (currCount > maxCount) {
        mode = v[size-1];
    }
    return mode;
}