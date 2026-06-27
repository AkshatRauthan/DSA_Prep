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

// Approach 1: DP
// Time: O(n) | Space: O(n)
// Idea: dp[i] = max subarray sum ending at index i
//       either extend previous subarray or start fresh at i
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

// Approach 2: Kadane's Algorithm
// Time: O(n) | Space: O(1)
// Idea: Same as DP but no need to store entire array
//       dp[i] only depends on dp[i-1] so just keep a variable
int maxSubArrayKadane(vector<int>& v) {
    int curSum = v[0];  // max subarray sum ending at current index
    int ans = v[0];

    for (int i=1; i<v.size(); i++){
        // extend previous subarray or start fresh at i
        curSum = max(curSum + v[i], v[i]);
        ans = max(ans, curSum);
    }
    return ans;
}