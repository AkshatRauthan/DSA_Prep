/**
 *  LC 2461: Maximum Sum of Distinct Subarrays With Length K
 *  Topics: Senior, Array, Hash Table, Sliding Window, Weekly Contest 318
 *
 *
 *  Description:
 *  You are given an integer array nums and an integer k.
 *  Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:
 *  - The length of the subarray is k, and
 *  - All the elements of the subarray are distinct.
 *  Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.
 *
 *
 *  Follow Ups: LC 2814: Same question but this time we can can have at least n unique elements in a valid window.
 *
 *  Input: nums = [1,5,4,2,9,9,9], k = 3
 *  Output: 15
 *  Explanation: The subarrays of nums with length 3 are:
 *	  - [1,5,4] which meets the requirements and has a sum of 10.
 *	  - [5,4,2] which meets the requirements and has a sum of 11.
 *	  - [4,2,9] which meets the requirements and has a sum of 15.
 *	  - [2,9,9] which does not meet the requirements because the element 9 is repeated.
 *	  - [9,9,9] which does not meet the requirements because the element 9 is repeated.
 *	We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions
 *
 */

#include "iostream"
#include "vector"
#include "unordered_map"
#include "memory_resource"

using namespace std;
std::pmr::unsynchronized_pool_resource pool;  // Creating a pool of statically allocated memory to use.... For reducing heaqp allocation time....

long long maximumSubarraySum(vector<int>& v, int k) {
	unordered_map<int, int> m;
	m.clear();

	int sIdx= 0;
	long long maxSum= 0, currSum= 0;
	for (int i= 0; i < v.size(); i++) {
		currSum+= (long long)v[i];
		m[v[i]]++;

		if (m.size() == k) maxSum= (maxSum > currSum) ? maxSum : currSum;

		if (i - sIdx + 1 == k) {
			currSum-= (long long)v[sIdx];
			if (m[v[sIdx]] == 1)
				m.erase(v[sIdx]);
			else
				m[v[sIdx]]--;
			sIdx++;
		}
	}
	return maxSum;
}