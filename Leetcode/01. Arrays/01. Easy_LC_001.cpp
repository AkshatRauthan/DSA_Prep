/**
 *  LC 01: Two Sum => Easy
 *  Topics: Arrays, Maps
 *  
 *  Follow Ups: 
 *  
 *  Description:
 *  Given an array of integers v and an integer x, return indices of the two numbers such that they add up to x.
 *  You may assume that each input would have exactly one solution, and you may not use the same element twice.
 *  You can return the answer in any order.
 *
 *  Input: nums = [2,7,11,15], target = 9
 *  Output: [0,1]
 *  Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 *
*/


#include "iostream"
#include "vector"
#include "unordered_map"
using namespace std;

vector<int> twoSum(vector<int> &v, int x){
    if (v.size() == 2) return {0, 1};

    unordered_map<int, int> m;
    int target;
    m.clear();

    for (int i=0; i<v.size(); i++){
        target = x-v[i];
        (target<0)? target * (-1): target;
        if (m.find(target) != m.end()){
            return {m[target], i};
        } else m[v[i]] = i;
    }

    return {0,1};
}
