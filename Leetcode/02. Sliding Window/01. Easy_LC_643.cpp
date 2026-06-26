/**
 *  LC 643: Maximum Average Subarray I => Easy
 *  Topics: Arrays, Maps
 *  
 *  Follow Ups: 
 *  
 *  Description:
 *  You are given an integer array nums consisting of n elements, and an integer k.
 *  Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value.
 *  Any answer with a calculation error less than 10-5 will be accepted.
 *
 *  Input: Input: nums = [1,12,-5,-6,50,3], k = 4
 *  Output: 12.75000
 *  Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
 *
*/


#include "iostream"
#include "vector"
using namespace std;

double findMaxAverage(vector<int>& v, int k) {
    int sum = 0, sIdx = 0, maxSum = 0, idx=0;

    for (int i=0; i<k; i++) sum += v[i];
    maxSum = sum;
    idx = k;

    while (idx < v.size()){
        sum += (v[idx] - v[sIdx]);
        sIdx++, idx++;
        maxSum = max(maxSum, sum);
    }

    return ((double)maxSum)/((double)k);
}
