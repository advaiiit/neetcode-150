#include<vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int totalNums = nums.size();
        int start = 0, end = nums.size() - 1;

        // Once this condition is checked, it means that min lies at the end of the sorted portion of the array
        if (nums[start] <= nums[end]) return nums[start];

        while (start + 1 < end) {
            int mid = start + (end - start) / 2;

            if (nums[start] <= nums[mid]) 
                start = mid;
            else 
                end = mid;
        }

        return (nums[start] < nums[end]) ? nums[start] : nums[end];
    }
};
// TC: O(log N) SC: O(1)