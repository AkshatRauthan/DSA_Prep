/**
 *  LC 567: Permutation in String
 *  Topics: Staff, Hash Table, String, Sliding Window
 *
 *  Follow Ups:
 *
 *  Description:
 *  Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
 *  In other words, return true if one of s1's permutations is the substring of s2.
 *
 *  Input: s1 = "ab", s2 = "eidbaooo"
 *  Output: true
 *  Explanation: s2 contains one permutation of s1 ("ba").
 *
 */

#include "iostream"
#include "vector"
using namespace std;

bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size()) return false;

    vector<int> freq1(26, 0), freq2(26, 0);

    // Build initial window
    for (int i = 0; i < s1.size(); i++) {
        freq1[s1[i] - 'a']++;
        freq2[s2[i] - 'a']++;
    }

    if (freq1 == freq2) return true; // first window is a substring, return true

    // Slide the window
    for (int i = s1.size(); i < s2.size(); i++) {
        freq2[s2[i] - 'a']++;             // add new char
        freq2[s2[i - s1.size()] - 'a']--; // remove old char
        if (freq1 == freq2) return true;
    }

    return false;
}