#include<vector>
using namespace std;

class Solution {
public:
    int brute(vector<int>& prices) {
        int maxProfit = 0;

        for (int i = 0; i < prices.size(); i++) {
          for (int j = i + 1; j < prices.size(); j++) 
            maxProfit = max(maxProfit, prices[j] - prices[i]);
        }

        return maxProfit;
    }
    // TC: O(N^2) SC: O(1)

    int optimal(vector<int>& prices) {
        int maxProfit = 0, minBuy = 1e4;

        for (int i = 0; i < prices.size(); i++) {
          minBuy = min(minBuy, prices[i]);
          maxProfit = max(maxProfit, prices[i] - minBuy);
        }

        return maxProfit;
    }
    // TC: O(N) SC: O(1)
};