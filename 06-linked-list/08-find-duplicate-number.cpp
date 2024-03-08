#include<vector>
using namespace std;

// nums contains integers from 1 to n. One of them is repeated. 
// Imagine this vector as a linked list with a loop. 
// You just need to return the starting point of the loop.

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast)
                break;
        }

        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};