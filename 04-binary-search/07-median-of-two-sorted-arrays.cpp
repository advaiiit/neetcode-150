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
    // TC: O(N1 + N2) SC: O(N1 + N2)

    double better(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int m = n1 + n2;
        int ind1 = m / 2 - 1, ind2 = m / 2;
        int i = 0, j = 0, k = 0;
        int count = 0, el1 = -1, el2 = -1;

        while (i < n1 && j < n2) {
            if (nums1[i] <= nums2[j]) {
                if (count == ind1) el1 = nums1[i];
                if (count == ind2) el2 = nums1[i];
                count++;
                i++;
            }
            else {
                if (count == ind1) el1 = nums2[j];
                if (count == ind2) el2 = nums2[j];
                count++;
                j++;
            }
        }

        while (i < n1) {
            if (count == ind1) el1 = nums1[i];
            if (count == ind2) el2 = nums1[i];
            count++;
            i++;
        }

        while (j < n2) {
            if (count == ind1) el1 = nums2[j];
            if (count == ind2) el2 = nums2[j];
            count++;
            j++;
        }

        return (m % 2) ? (double) el2 : (double) (el1 + el2) / 2;
    }
    // TC: O(N1 + N2) SC: O(1)

    double optimal(vector<int>& nums1, vector<int>& nums2) {
    // Intution 

    // nums1 = [1, 3, 4, 7, 10, 12]
    // nums2 = [2, 3, 6, 15]
    //                             left              right
    // When merged together => [1, 2, 3, 3, 4 | 6, 7, 10, 12, 15]

    // We need to find partitions in both the arrays such that left half of nums1, and num2
    // make the left half of the merged array, and right half of nums1, and nums2 make the 
    // right half of the merged array.

    //           mid1
    // [1, 3, 4 | 7, 10, 12]
    //        l1  r1

    //            mid2
    //     [2, 3 | 6, 15]
    //        l2  r2

    // We know that size of the merged array is 10, hence its left part will contain 5 nos.
    // If we select the first 3 nos. from nums1, then we would have to select 5 - 3 = 2 nos. 
    // from nums2 to complete the left part of the merged array

    // We know that we have found the correct partition mid1 and mid2 when l1 <= r2 and l2 <= r1

    // Once we find the correct partitions, we can find the median using the following formula
    // median = (max(l1, l2) + min(r1, r2)) / 2     (for even)
    // median = max(l1, l2)                         (for odd)

    // We perform binary search to find the correct partitions.


        // Binary search will be performed on the shoter array
        int n1 = nums1.size(), n2 = nums2.size();
        if (n1 > n2) return optimal(nums2, nums1);
        
        int low = 0, high = n1;
        int leftNums = (n1 + n2 + 1) / 2; // we add 1 to maintain symmetry incase n1 + n2 is odd

        while (low <= high) {
            int mid1 = (low + high) >> 1;
            int mid2 = leftNums - mid1;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;

            if (mid1 < n1) r1 = nums1[mid1];
            if (mid2 < n2) r2 = nums2[mid2];
            if (mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
            if (mid2 - 1 >= 0) l2 = nums2[mid2 - 1];

            if (l1 <= r2 && l2 <= r1)
                return ((n1 + n2) % 2) ? max(l1, l2) : (double) (max(l1, l2) + min(r1, r2)) / 2;
            else if (l1 > r2) 
                high = mid1 - 1;
            else 
                low = mid1 + 1;
        }

        return -1;
    }
    // TC: O(log(min(N1, N2))) SC: O(1)
};