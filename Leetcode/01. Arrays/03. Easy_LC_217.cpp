/**
 *  LC 217: Duplicate Elements => Easy
 *  Topics: Arrays, Maps
 *  
 *  Follow Ups: 
 *  
 *  Description:
 *  Given an integer array nums, return true if any value appears at least twice in the array, 
 *  and return false if every element is distinct.
 *
 *  Input: nums = [1,2,3,1]
 *  Output: true
 *  Explanation: The element 1 occurs at the indices 0 and 3.
 *
*/


#include "iostream"
#include "vector"
#include "unordered_set"
using namespace std;

bool containsDuplicate(vector<int>& v) {
    unordered_set<int> s;
    for (auto x: v){
        if (s.find(x) != s.end()){
            s.clear();
            return true;
        } else s.insert(x);
    }
    return false;
}