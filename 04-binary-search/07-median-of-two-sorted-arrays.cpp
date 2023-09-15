#include<vector>
using namespace std;

class Solution {
public:
    double brute(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int m = n1 + n2;
        int i = 0, j = 0, k = 0;
        vector<int> mergedNums;

        while (i < n1 && j < n2) {
            if (nums1[i] <= nums2[j]) 
                mergedNums.push_back(nums1[i++]);
            else 
                mergedNums.push_back(nums2[j++]);
        }

        while (i < n1) mergedNums.push_back(nums1[i++]);
        while (j < n2) mergedNums.push_back(nums2[j++]);

        return (m % 2) ? (double) mergedNums[m / 2] :
            (double) (mergedNums[m / 2 - 1] + mergedNums[m / 2]) / 2;
    }
    // TC: O(N1 + N2) SC: O(1)

    
};