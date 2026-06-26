/**
 *  LC 53: Maximum Subarray => Medium
 *  Topics: Arrays, DP, Kadane's Algo, Two Pointers, Sliding Window, Prefix Sum
 *  
 *  Follow Ups: 
 *  
 *  Description:
 *  Given an integer array nums, find the subarray with the largest sum, and return its sum.
 *
 *  Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 *  Output: 6
 *  Explanation: The subarray [4,-1,2,1] has the largest sum 6.
 *
*/


#include "iostream"
#include "vector"
using namespace std;

int maxSubArray(vector<int>& v) {
    vector<int> dp = vector<int>(v.size(), 0);
    dp[0] = v[0];
    int ans = v[0];
    for (int i=1; i<v.size(); i++){
        dp[i] = max(dp[i-1] + v[i], v[i]);
        ans = max(ans, dp[i]);
    }
    return ans;
}