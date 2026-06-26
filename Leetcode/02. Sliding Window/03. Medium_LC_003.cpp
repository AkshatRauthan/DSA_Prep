/**
 *  LC 03: Longest Substring Without Repeating Characters
 *  Topics: Staff, Hash Table, String, Sliding Window
 *  
 *  Follow Ups: 
 *  
 *  Description:
 *  Given a string s, find the length of the longest substring without duplicate characters.
 *
 *  Input: s = "abcabcbb"
 *  Output: 3
 *  Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
 *
*/


#include "iostream"
#include "string"
#include "vector"

using namespace std;

// O(n) avg, worst case O(n^2) due to removal of ele. index form array
int lengthOfLongestSubstring(string s) {
    vector<int> prevIdx = vector<int>(260, -1);

    int maxLen = !s.empty(), sIdx = 0, temp;

    for (int i = 0; i < s.length(); i++) {
        if (prevIdx[s[i]] == -1) { // No prev occurance
            prevIdx[s[i]] = i;
        } else { // Prev occurance on index prevIdx[i]
            // Remove all elements btw sIdx and prevIdx[s[i]] from range [their idx = -1]
            temp = prevIdx[s[i]];
            for (int j = sIdx; j <= prevIdx[s[i]]; j++)
                prevIdx[s[j]] = -1;
            sIdx = temp + 1;
        }
        prevIdx[s[i]] = i;
        maxLen = max(maxLen, i - sIdx + 1);
    }

    return maxLen;
}

// TC O(n)... No removal of characters from prevIdx vector
// Optimisation => Dont remove elements indexes from prevIdx => We can simply check that if the idx of current character is 
//                 less than then the sIdx or strting of our window it is not occuring in window......
//                 so we can directly take prevIdx[s[i]]+1 as new window starting...
int lengthOfLongestSubstring_Optimal(string s) {
    if (s.empty()) return 0;  // bug 2 fix
    
    vector<int> prevIdx = vector<int>(260, -1);

    int maxLen = 0, sIdx = 0, temp;

    for (int i=0; i<s.length(); i++){

        if (prevIdx[s[i]] < sIdx){
            prevIdx[s[i]] = i;

        } else {
            sIdx = prevIdx[s[i]] + 1;
        }
        prevIdx[s[i]] = i;  // bug 3 fix
        maxLen = max(maxLen, i-sIdx+1);
    }

    return maxLen;
}