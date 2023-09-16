#include<vector>
#include<unordered_set>
#include<string>
using namespace std;

class Solution {
public:
    int usingSet(string s) {
        int maxLen = 0, left = 0, right = 0;
        unordered_set<char> charSet;

        while (right < s.length()) {
            if (charSet.find(s[right]) == charSet.end()) {
                charSet.insert(s[right]);
                maxLen = max(maxLen, right - left + 1);
                right++;
            } else {
                charSet.erase(s[left]);
                left++;
            }
        }

        return maxLen;
    }
    // TC: O(N) SC: O(N)

    int usingFixedSizeVector(string s) {
        int maxLen = 0, left = 0, right = 0;
        vector<int> charFreq(128, -1);

        while (right < s.length()) {
            if (charFreq[s[right]] == -1) {
                charFreq[s[right]]++;
                maxLen = max(maxLen, right - left + 1);
                right++;
            } else {
                charFreq[s[left]]--;
                left++;
            }
        }

        return maxLen;
    }
    // TC: O(N) SC: O(128)
};