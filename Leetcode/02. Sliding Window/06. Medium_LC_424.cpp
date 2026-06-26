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