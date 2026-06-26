#include "iostream"
#include "vector"
using namespace std;

/**
 *  LC 152: Maximum Product Subarray => Medium
 *  Topics: Arrays, DP
 *  
 *  Follow Up: Now make it with 0(1) space
 * 
 *  Description:
 *  Given an integer array nums, find a subarray that has the largest product, and return the product.
 *  The test cases are generated so that the answer will fit in a 32-bit integer.
 *  Note that the product of an array with a single element is the value of that element.
 *
 *  Input: nums = [2,3,-2,4]
 *  Output: 6
 *  Explanation: [2,3] has the largest product 6.
 *
*/

int maxProduct(vector<int>& v) {
    vector<vector<int>> dp = vector<vector<int>>(v.size(), vector<int>(2, 1));

    // dp[][0] => min
    // dp[][1] => max

    dp[0][0] = v[0];
    dp[0][1] = v[0];
    int ans = v[0];

    for (int i=1; i<v.size(); i++){
        // set min
        dp[i][0] = min(v[i], min(v[i] * dp[i-1][0], v[i] * dp[i-1][1]));

        // set max
        dp[i][1] = max(v[i], max(v[i] * dp[i-1][0], v[i] * dp[i-1][1]));

        ans = max(ans, dp[i][1]);
    }

    return ans;
}

/**
 *  Here we are only looking of dp[i-1] only last steps values, so instread of them we can simply store the last steps values in variables...
 *  To implement space optimised DP
 */
int maxProduct_01_Space(vector<int>& v) {
    // dp[][0] => replace by minP => min
    // dp[][1] => replace by minP => max

    int minP = v[0], maxP = v[0], prevMinP, prevMaxP;
    int ans = v[0];

    for (int i=1; i<v.size(); i++){
        prevMinP = minP, prevMaxP = maxP;

        // set min
        minP = min(v[i], min(v[i] * prevMinP, v[i] * prevMaxP));

        // set max
        maxP = max(v[i], max(v[i] * prevMinP, v[i] * prevMaxP));

        ans = max(ans, maxP);
    }

    return ans;
}