#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> powerSet;

        getPowerSet(0, nums, subset, powerSet);

        return powerSet;
    }

    void getPowerSet(int index, vector<int> nums, vector<int>& subset, vector<vector<int>>& powerSet) {
        if (index == nums.size()) {
            powerSet.push_back(subset);
            return;
        }
        
        subset.push_back(nums[index]);
        getPowerSet(index + 1, nums, subset, powerSet);
        subset.pop_back();
        getPowerSet(index + 1, nums, subset, powerSet);
    }
};
// TC: O(2^N * N) Recursion + Copyingss
// SC: O(N) Stack Space