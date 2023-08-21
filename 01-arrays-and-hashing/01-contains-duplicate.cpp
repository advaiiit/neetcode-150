#include<vector>
#include<map>
#include<unordered_set>
using namespace std;

class Solution {
public:

    bool brute(vector<int>& nums) {
        int totalNums = nums.size();
        
        for (int i = 0; i < totalNums; i++) {
            int currNum = nums[i];
            for (int j = 0; j < totalNums; j++) {
                if (i == j) continue;
                if (currNum == nums[j]) 
                    return true;
            }
        }

        return false;
    }
    // TC: O(N^2) SC: O(1)

    bool usingHashMap(vector<int>& nums) {
        unordered_map<int, int> numFreq;

        for (int num : nums) {
            if (numFreq[num]) 
                return true;
            else 
                numFreq[num]++;
        }

        return false;
    }
    // TC: O(N) SC: O(N)

    bool usingSet(vector<int>& nums) {
        return (nums.size() > unordered_set<int>(nums.begin(), nums.end()).size());
    }
    // TC: O(N) SC:O(N)
};