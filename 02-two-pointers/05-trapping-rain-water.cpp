#include<vector>
using namespace std;

class Solution {
public:
    int brute(vector<int>& height) {
        int waterTrapped = 0, numBars = height.size();

        for (int i = 1; i < numBars - 1; i++) {
            int currHeight = height[i];
            int leftGreatest = currHeight, rightGreatest = currHeight;
            
            for (int j = i - 1; j >= 0; j--) 
                leftGreatest = max(leftGreatest, height[j]);

            for (int j = i + 1; j < numBars; j++)
                rightGreatest = max(rightGreatest, height[j]);

            waterTrapped += min(leftGreatest, rightGreatest)- currHeight;
        }

        return waterTrapped;
    }
    // TC: O(N^2) SC: O(1)

    int extraSpace(vector<int>& height) {
        int waterTrapped = 0, numBars = height.size();
        int leftGreat = 0, rightGreat = 0;
        vector<int> leftGreatest(numBars), rightGreatest(numBars);

        for (int i = 0; i < numBars; i++) {
            leftGreat = max(leftGreat, height[i]);
            leftGreatest[i] = leftGreat;

            int rightIndex = numBars - i - 1;
            rightGreat = max(rightGreat, height[rightIndex]);
            rightGreatest[rightIndex] = rightGreat;
        }

        for (int i = 1; i < numBars - 1; i++) 
            waterTrapped += min(leftGreatest[i], rightGreatest[i]) - height[i];
        
        return waterTrapped;
    }
    // TC: O(N) SC: O(N)

    int twoPointer(vector<int>& height) {
        int waterTrapped = 0;
        int left = 0, right = height.size() - 1;
        int leftGreat = 0, rightGreat = 0;

        while (left < right) {
            if (height[left] <= height[right]) {
                if (height[left] >= leftGreat) 
                    leftGreat = height[left];
                else 
                    waterTrapped += leftGreat - height[left];
                left++;
            } else {
                if (height[right] >= rightGreat)
                    rightGreat = height[right];
                else 
                    waterTrapped += rightGreat - height[right];
                right--;
            }
        }

        
        return waterTrapped;
    }
    // TC: O(N) SC: O(1)
};