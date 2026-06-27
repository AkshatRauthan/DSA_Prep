#include "iostream"
#include "vector"
#include "unordered_map"
#include "climits"
#include "memory_resource"

using namespace std;
std::pmr::unsynchronized_pool_resource pool;

/**
 *  Approach: Sliding Window + Frequency Counter
 *
 *  Expand window from right until all chars of t are satisfied (have == required).
 *  Then shrink from left to find the minimum valid window.
 *  Use `need` to store required frequencies, `window` to track current window frequencies.
 *  Use `have/required` counter to avoid O(m) map comparison on each step — O(n+m) overall.
 */
string minWindow(string s, string t) {
    unordered_map<char, int> need, window;
    for (char c : t) need[c]++;

    int sIdx = 0, minLen = INT_MAX, minSIdx = 0;
    int have = 0;
    int required = need.size(); // unique chars in t that need to be satisfied

    for (int i=0; i<s.length(); i++) {
        window[s[i]]++;

        // check if current char satisfies a requirement
        if (need.count(s[i]) && window[s[i]] == need[s[i]])
            have++;

        // valid window => try shrinking from left
        while (have == required) {
            if (i - sIdx + 1 < minLen) {
                minLen = i - sIdx + 1;
                minSIdx = sIdx;
            }

            // remove leftmost char from window
            window[s[sIdx]]--;

            // if removing it breaks a requirement => window invalid again
            if (need.count(s[sIdx]) && window[s[sIdx]] < need[s[sIdx]])
                have--;

            sIdx++;
        }
    }

    return minLen == INT_MAX ? "" : s.substr(minSIdx, minLen);
}