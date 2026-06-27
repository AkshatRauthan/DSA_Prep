/**
 *  LC 204. Fruit Into Baskets
 *  Topics: Staff, Array, Hash Table, Sliding Window, Weekly Contest 102
 *
 *
 *  Description:
 *  You are visiting a farm that has a single row of fruit trees arranged from left to right.
 *  The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.
 *  You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:
 *  - You only have two baskets, and each basket can only hold a single type of fruit.
 *  - Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right.
 *  - Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
 *  Given the integer array fruits, return the maximum number of fruits you can pick.
 *
 *  Input: fruits = [1,2,3,2,2]
 *  Output: 4
 *  Explanation: We can pick from trees [2,3,2,2].
 *  If we had started at the first tree, we would only pick from trees [1,2].
 *
 */



#include "iostream"
#include "vector"
#include "unordered_map"
#include "climits"

using namespace std;

int totalFruit(vector<int>& v) {
	int maxLen=1, sIdx=0, temp;

	unordered_map<int, int> m;
	m.clear();

	for (int i=0; i<v.size(); i++) {
        if (m.find(v[i]) == m.end()){                   // New Element
            if (m.size() < 2){                            // Space left for new element type => No window modification
                m.insert({v[i], i});
            }
            else {                                         // No space for new element type => Modify window
                temp = INT_MAX;                            // temp => idx of ele to remove from window
                for (auto p: m){
                    temp = min(temp, p.second);
                }
                m.erase(v[temp]);
                m.insert({v[i], i});
                sIdx = temp+1;
            }
        }
        else {                                          // Existing Element: Continue
            m[v[i]] = i;
        }

        maxLen = max(maxLen, i-sIdx+1);
	}

    return maxLen;
}