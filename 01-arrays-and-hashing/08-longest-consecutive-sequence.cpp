#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int usingHashMap(vector<int>& nums) {
        int maxLen = 0;
        unordered_map<int, int> map;

        for (int num : nums) map[num]++;

        for (int i = 0; i < nums.size(); i++) {
            if (map[nums[i] - 1]) 
                continue;
            else {
                int currNum = nums[i];
                int currLen = 1;

                while(map[++currNum]) currLen++;
                
                maxLen = max(maxLen, currLen);
            }
        }

        return maxLen;
    }
    // TC: O(N) SC: O(N)

    int usingSet(vector<int>& nums) {
        int maxLen = 0;
        unordered_set<int> set;

        for (int num : nums) set.insert(num);

        for (int i = 0; i < nums.size(); i++) {
            if (set.find(nums[i] - 1) != set.end()) 
                continue;
            else {
                int currNum = nums[i];
                int currLen = 1;

                while(set.find(++currNum) != set.end()) 
                    currLen++;
                
                maxLen = max(maxLen, currLen);
            }
        }

        return maxLen;
    }
    // TC: O(N) SC: O(N)
};