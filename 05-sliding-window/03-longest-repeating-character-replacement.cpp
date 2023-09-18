#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int brute(string s, int k) {
        int maxLen = 0, strLen = s.length();

        for (int i = 0; i < strLen; i++) {
            for (int j = i + 1; j < strLen; j++) {
                int maxFreq = 0, substrLen = j - i + 1;
                unordered_map<char, int> freqMap;

                for (int k = i; k <= j; k++) freqMap[s[k]]++;
                for (auto it : freqMap) maxFreq = max(maxFreq, it.second);

                if (substrLen - maxFreq <= k) maxLen = max(maxLen, substrLen);
            }
        }

        return maxLen;
    }
    // TC: O(N^4) SC: O(N)
};