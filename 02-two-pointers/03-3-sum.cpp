#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> brute(vector<int>& nums) {
        int totalNums = nums.size();
        unordered_set<vector<int>> triplets;

        for (int i = 0; i < totalNums; i++) {
            for (int j = i + 1; j < totalNums; j++) {
                for (int k = j + 1; k < totalNums; k++) {
                    if (nums[i] + nums[j] + nums[k] != 0) continue;

                    vector<int> triplet = {nums[i], nums[j], nums[k]};
                    sort(triplet.begin(), triplet.end());
                    triplets.insert(triplet);
                }
            }
        }

        return vector<vector<int>> (triplets.begin(), triplets.end());
    }
    // TC: O(N^3) SC: O(N)

    vector<vector<int>> sorting(vector<int>& nums) {
        int totalNums = nums.size();
        unordered_set<vector<int>> triplets;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < totalNums; i++) {
            int left = i + 1, right = totalNums - 1;
            int target = 0 - nums[i];
            
            while (left < right) {
                int sum = nums[left] + nums[right];

                if (sum == target) {
                    vector<int> triplet = {nums[i], nums[left], nums[right]};
                    sort(triplet.begin(), triplet.end());
                    triplets.insert(triplet);

                    left++; right--;
                } else if (sum < target) left++;
                else right--;
            }
        }

        return vector<vector<int>> (triplets.begin(), triplets.end());
    }
    // TC: O(N^2) SC: O(N)

    vector<vector<int>> spaceOptimized(vector<int>& nums) {
        int totalNums = nums.size();
        vector<vector<int>> triplets;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < totalNums; i++) {
            if (i > 0 && nums[i - 1] == nums[i]) continue;

            int left = i + 1, right = totalNums - 1;
            int target = 0 - nums[i];
            
            while (left < right) {
                int sum = nums[left] + nums[right];

                if (sum == target) {
                    triplets.push_back({nums[i], nums[left], nums[right]});

                    while (left < right && nums[left + 1] == nums[left]) left++;
                    while (left < right && nums[right - 1] == nums[right]) right--;

                    left++; right--;
                } else if (sum < target) left++;
                else right--;
            }
        }

        return triplets;
    }
    // TC: O(N^2) SC:(1)
};