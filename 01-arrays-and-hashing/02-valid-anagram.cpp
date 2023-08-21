#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool sorting(string s, string t) {
        if (s.length() != t.length()) 
            return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
    // TC: O(2 * NlogN) SC: O(1)

    bool usingTwoHashMaps(string s, string t) {
        if (s.length() != t.length()) 
            return false;

        unordered_map<char, int> sFreq, tFreq;
        for (int i = 0; i < s.length(); i++) {
            sFreq[s[i]]++;
            tFreq[t[i]]++;
        }

        return sFreq == tFreq;
    }
    // TC: O(2N) SC: O(2N)

    bool usingOneHashMap(string s, string t) {
        if (s.length() != t.length()) 
            return false;

        unordered_map<char, int> sFreq;
        for (char c : s) sFreq[c]++;

        for (char c : t) {
            if (sFreq[c]) 
                sFreq[c]--;
            else 
                return false;
        }

        return true;
    }
    // TC: O(2N) SC: O(N)
};