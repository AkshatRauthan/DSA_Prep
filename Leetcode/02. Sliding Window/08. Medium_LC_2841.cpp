/**
 *  LC 2841: Maximum Sum of Almost Unique Subarray
 *  Topics: Staff, Array, Hash Table, Sliding Window, Biweekly Contest 112
 *
 *
 *  Description:
 *  You are given an integer array nums and two positive integers m and k.
 *  Return the maximum sum out of all almost unique subarrays of length k of nums. If no such subarray exists, return 0.
 *  A subarray of nums is almost unique if it contains at least m distinct elements.
 *  A subarray is a contiguous non-empty sequence of elements within an array.
 *
 *
 *  Input: nums = [5,9,9,2,4,5,4], m = 1, k = 3
 *  Output: 23
 *  Explanation: There are 5 almost unique subarrays of size k.
 *  These subarrays are [5, 9, 9], [9, 9, 2], [9, 2, 4], [2, 4, 5], and [4, 5, 4].
 *  Among these subarrays, the one with the maximum sum is [5, 9, 9] which has a sum of 23.
 *
 */


#include "iostream"
#include "vector"
#include "unordered_map"
#include "memory_resource"

using namespace std;
std::pmr::unsynchronized_pool_resource pool;
// Creating a pool of statically allocated memory to use.... For reducing heaqp allocation time....

long long maxSum(vector<int>& v, int n, int k) {
    pmr::unordered_map<int, int> m(&pool);

    int sIdx = 0;
    long long maxSum = 0, currSum = 0;
    for (int i=0; i<v.size(); i++) {
        currSum += (long long)v[i];
        m[v[i]]++;

        if (m.size() >= n)
            maxSum = (maxSum > currSum) ? maxSum : currSum;

        if (i - sIdx + 1 == k) {
            currSum -= (long long)v[sIdx];
            if (m[v[sIdx]] == 1)
                m.erase(v[sIdx]);
            else
                m[v[sIdx]]--;
            sIdx++;
        }
    }
    return maxSum;
}