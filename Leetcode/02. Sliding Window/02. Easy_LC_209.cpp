/**
 *  LC 209: Minimum Size Subarray Sum => Easy
 *  Topics: Array, Binary Search, Sliding Window, Prefix Sum
 *  
 *  Follow Ups: 
 *  
 *  Description:
 *  Given an array of positive integers nums and a positive integer target, return the minimal length 
 *  of a subarray whose sum is greater than or equal to target. 
 *  If there is no such subarray, return 0 instead.
 *
 *  Input: target = 7, nums = [2,3,1,2,4,3]
 *  Output: 2
 *  Explanation: The subarray [4,3] has the minimal length under the problem constraint.
 *
*/

#include "iostream"
#include "vector"
#include "climits"
using namespace std;

int minSubArrayLen(int x, vector<int>& v) {
    int minL = INT_MAX;
    int sIdx = 0, sum = 0;

    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
        while (sum >= x) {
            minL = min(minL, i - sIdx + 1);
            sum -= v[sIdx];
            sIdx++;
        }
    }

    return minL == INT_MAX ? 0 : minL;
}