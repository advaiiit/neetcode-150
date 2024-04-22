#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> powerSet;

        sort(nums.begin(), nums.end());
        getPowerSet(0, nums, subset, powerSet);

        return powerSet;
    }

    void getPowerSet(int index, vector<int> nums, vector<int>& subset, vector<vector<int>>& powerSet) {
        powerSet.push_back(subset);
        
        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i - 1]) {
                continue;
            }
            subset.push_back(nums[i]);
            getPowerSet(i + 1, nums, subset, powerSet);
            subset.pop_back();
        }
    }
};
// TC: O(NlogN + O(2^N * N)) // Initial sorting + Recursion * Copying
// TC: O(N) // Recursion Stack