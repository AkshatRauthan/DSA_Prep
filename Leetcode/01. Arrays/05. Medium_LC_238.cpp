#include "iostream"
#include "vector"
using namespace std;

/**
 *  LC 238: Product of Array Except Self => Medium
 *  Topics: Arrays, Prefix Sum
 *  
 *  Follow Ups: After this cann you write one that used O(1) space as well.... 
 *  [ Initially using saperate preP and nextP prefix arrays, after that this one using ans ARray as nextP and inout array as prevP ]
 *  
 *  Description:
 *  Given an integer array nums, find a subarray that has the largest product, and return the product.
 *  The test cases are generated so that the answer will fit in a 32-bit integer.
 *  Note that the product of an array with a single element is the value of that element.
 *  
 *
 *  Input: nums = [1,2,3,4]
 *  Output: [24,12,8,6]
 *
*/

vector<int> productExceptSelf(vector<int>& v) {
    vector<int> ans = vector<int>(v.size(), 1); // prevP, v=> nextP

    ans[0] = v[0];
    for (int i = 1; i < v.size(); i++)
        ans[i] = ans[i - 1] * v[i];

    for (int i = v.size()-2; i >= 0; i--)
        v[i] *= v[i + 1];

    ans[v.size() - 1] = ans[v.size() - 2];

    for (int i = v.size() - 2; i > 0; i--) // ans => prevP, v => nextP
        ans[i] = ans[i-1] * v[i+1];

    ans[0] = v[1];
    return ans;
}