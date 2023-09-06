#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int brute(vector<int>& heights) {
        int maxArea = 0, totalBars = heights.size();

        for (int i = 0; i < totalBars; i++) {
            int minHeight = heights[i];

            for (int j = i; j < totalBars; j++) {
                minHeight = min(minHeight, heights[j]);
                maxArea = max(maxArea, minHeight * (j - i + 1));
            }
        }

        return maxArea;
    }
    // TC: O(N^2) SC:(1)

    int multiPass(vector<int>& heights) {
        int maxArea = 0, totalBars = heights.size();
        vector<int> prevSmall(totalBars), nextSmall(totalBars);
        stack<int> stack;

        for (int i = 0; i < totalBars; i++) {
            while (!stack.empty() && heights[stack.top()] >= heights[i]) 
                stack.pop();

            prevSmall[i] = (stack.empty()) ? 0 : stack.top() + 1;
            stack.push(i);
        }

        while (!stack.empty()) stack.pop();

        for (int i = totalBars - 1; i >= 0; i--) {
            while (!stack.empty() && heights[stack.top()] >= heights[i]) 
                stack.pop();
            
            nextSmall[i] = (stack.empty()) ? totalBars - 1 : stack.top() - 1;
            stack.push(i);
        }

        for (int i = 0; i < totalBars; i++) 
            maxArea = max(maxArea, (heights[i] * (nextSmall[i] - prevSmall[i] + 1)));

        return maxArea;
    }
    // TC: O(N) SC: O(N)

    int onePass(vector<int>& heights) {
        int totalBars = heights.size(), maxArea = 0;
        stack<int> stack;
        
        for (int i = 0; i <= totalBars; i++) {
            while (!stack.empty() && (i == totalBars || heights[stack.top()] >= heights[i])) {
                int height, width;
                
                height = heights[stack.top()];
                stack.pop();
                width = (stack.empty()) ? i : i - stack.top() - 1;
 
                maxArea = max(maxArea, height * width);
            }
            stack.push(i);
        }

        return maxArea;
    }
    // TC: O(N) SC: O(N)
};
