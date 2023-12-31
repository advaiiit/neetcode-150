#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] <= nums[right]) {
                if (nums[mid] <= target &&  target <= nums[right]) {
                    if (nums[mid] == target) 
                        return mid;
                    left = mid + 1;
                } else 
                    right = mid - 1;
            } else {
                if (nums[left] <= target && target <= nums[mid]) {
                    if (nums[mid] == target) 
                        return mid;
                    right = mid - 1;
                } else 
                    left = mid + 1;
            }
        }

        return -1; 
    }
};
// TC: O(NlogN) SC: O(1) 