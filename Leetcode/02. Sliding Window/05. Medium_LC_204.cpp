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