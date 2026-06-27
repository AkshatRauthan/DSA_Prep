/**
 *  LC 3: Longest Substring Without Repeating Characters
 *  Topics: Staff, Array, Hash Table, Sliding Window
 *
 *
 *  Description:
 *  You are given a string s and an integer k.
 *  You can choose any character of the string and change it to any other uppercase English character.
 *  You can perform this operation at most k times.
 *  Return the length of the longest substring containing the same letter you can get after performing the above operations
 *
 *
 *  Input: s = "AABABBA", k = 1
 *  Output: 4
 *  Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
 *  The substring "BBBB" has the longest repeating letters, which is 4.
 *  There may exists other ways to achieve this answer too.
 *
 */


#include "iostream"
#include "vector"
#include "unordered_map"

using namespace std;

// For creating a valid window => We can have n number of single character A with maxFreq + max K other characters
// So whenever windowSize - maxFreq == k+1, remove starign element of window....
int characterReplacement(string s, int k) {
    unordered_map<char, int> m;
    m.clear();

    int maxLen=0, sIdx=0, maxFreq=0;

    for (int i=0; i<s.length(); i++){
        m[s[i]]++;

        maxFreq = max(maxFreq, m[s[i]]);

        if ((i-sIdx+1) - maxFreq > k){                        // Invalid Window
            m[s[sIdx]]--;
            sIdx++;
        }

        maxLen = max(maxLen, i-sIdx+1);
    }

    return maxLen;
}