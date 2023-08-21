#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> brute(vector<int>& nums, int target) {
        int totalNums = nums.size();

        for (int i = 0; i < totalNums; i++) {
            for (int j = 0; j < totalNums; j++) {
                if (i == j) continue;
                if (nums[i] + nums[j] == target)
                    return {i, j};
            }
        }

        return {-1, -1};
    }
    // TC: O(N^2) SC: O(1)

    vector<int> twoPassHashMap(vector<int>& nums, int target) {
        int totalNums = nums.size();
        unordered_map<int, int> map;

        for (int i = 0; i < totalNums; i++) 
            map[nums[i]] = i;

        for (int i = 0; i < totalNums; i++) {
            int targetNum = target - nums[i];
            if (map.find(targetNum) != map.end() && i != map[targetNum])
                return {i, map[targetNum]};
        }

        return {-1, -1};
    }
    // TC: O(2N) SC: O(N)

    vector<int> onePassHashMap(vector<int>& nums, int target) {
        int totalNums = nums.size();
        unordered_map<int, int> map;

        for (int i = 0; i < totalNums; i++) {
            int targetNum = target - nums[i];
            if (map.find(targetNum) != map.end() && i != map[targetNum])
                return {i, map[targetNum]};

            map[nums[i]] = i;
        }

        return {-1, -1};
    }
    // TC: O(N) SC: O(N)
};