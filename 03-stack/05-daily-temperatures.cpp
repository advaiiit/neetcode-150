#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int numDays = temperatures.size();
        vector<int> res(numDays);
        stack<int> indexStack;   

        for (int i = numDays - 1; i >= 0; i--) {
            while (!indexStack.empty() && temperatures[indexStack.top()] <= temperatures[i]) 
                indexStack.pop();

            res[i] = (indexStack.empty()) ? 0 : indexStack.top() - i;
            
            indexStack.push(i);
        }

        return res;
    }
};
// TC: O(N) SC: O(N)