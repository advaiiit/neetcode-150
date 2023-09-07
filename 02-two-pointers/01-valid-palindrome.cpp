#include<string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int start, end;
        string newS = "";

        for (char c : s) {
            if (isAlphaNumeric(c))
                newS.push_back(toLowercase(c));
        }

        start = 0;
        end = newS.length() - 1;

        while (start < end) {
            if (newS[start++] != newS[end--])
                return false;
        }

        return true;
    }

    bool isAlphaNumeric(char c) {
        return ('0' <= c && c <= '9') || ('a' <= c &&  c <= 'z') || ('A' <= c && c <= 'Z');
    }

    char toLowercase(char c) {
        return ('A' <= c && c <= 'Z') ? c - 'A' + 'a' : c;
    }
};
// TC: O(N) SC: O(1)