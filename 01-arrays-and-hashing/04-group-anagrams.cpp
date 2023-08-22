#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
    vector<vector<string>> hashMapAndSorting(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> anagramMap;

        for (string s : strs) {
            string currString = s;
            sort(s.begin(), s.end());
            anagramMap[s].push_back(currString);
        }

        for (auto it : anagramMap) res.push_back(it.second);

        return res;
    }
    // N - No. of string, L - Length of string
    // TC: O(N * LlogL) + O(N) 
    // SC: O(N)
};