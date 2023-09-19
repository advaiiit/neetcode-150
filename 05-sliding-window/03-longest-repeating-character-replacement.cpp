#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int brute(string s, int k) {

        // Generate all substrings
        // If substring - total number of max freq char of substrint <= k,
        // then the rest of the characters can be replaced with the max freq char,
        // hence the substring will be a valid one

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
    // TC: O(N^4) SC: O(N^2)

    int slidingWindow(string s, int k) {

        // Instead of generating all substring, 
        // use a sliding window which expands when the window is valid
        // and shrinks when it is not valid

        int maxLen = 0, left = 0, right = 0;

        while (right < s.length()) {
            int substrLen = right - left + 1;
            int maxFreq = 0;
            unordered_map<char, int> charFreq;

            for (int i = left; i <= right; i++) charFreq[s[i]]++;
            for (auto it : charFreq) maxFreq = max(maxFreq, it.second);

            if (substrLen - maxFreq <= k) {
                maxLen = max(maxLen, substrLen);
                right++;
            } else {
                charFreq[s[left]]--;
                left++;
            }
        }
        
        return maxLen;
    }
    // TC: O(N^2) SC: O(N^2)
};

class BinarySearchWithSlidingWindow {
public:
    int characterReplacement(string s, int k) {

        // We know that if a substring of length n is valid then all 
        // of its substrings of length n - i are valid. 
        // Binary search the length of the substring, if the length is 
        // valid then increase the length else we decrease it.

        int maxLen = 0, left = 0, right = s.length() + 1;;

        while (left + 1 < right) {
            int mid = (left + right) >> 1;

            if (isValidSubstring(s, mid, k))
                left = mid;
            else 
                right = mid;
        }
        
        return left;
    }

private: 
    bool isValidSubstring(string s, int substrLen, int k) {

        // Check if there exists any valid substring of given length 

        int start = 0, maxFreq = 0;
        vector<int> freqMap(26);

        for (int end = 0; end < s.length(); end++) {
            freqMap[s[end] - 'A']++;

            if (end - start + 1 > substrLen) {
                freqMap[s[start] - 'A']--;
                start += 1;
            }

            maxFreq = max(maxFreq, freqMap[s[end] - 'A']);
            if (substrLen - maxFreq <= k) return true;
        }

        return false;
    }
};
// TC: O(NlogN) SC: O(26 * logN)