#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> combination;
        vector<vector<int>> uniqueCombinations;

        findUniqueCombinations(0, target, candidates, combination, uniqueCombinations);

        return uniqueCombinations;
    }

private: 
    void findUniqueCombinations(int index, int target, vector<int> candidates,
     vector<int>& combination, vector<vector<int>>& uniqueCombinations) {
        if (index == candidates.size()) {
            if (target == 0) {
                uniqueCombinations.push_back(combination);
            }
            return;
        }

        int pick = candidates[index];
        if (pick <= target) {
            combination.push_back(pick);
            findUniqueCombinations(index, target - pick, candidates, combination, uniqueCombinations);
            combination.pop_back();
        }
        findUniqueCombinations(index + 1, target, candidates, combination, uniqueCombinations);

        return;
     }
};
// TC: O(2^T * L)
// SC: L * N
// T - Target (If T = 10 and candidates contain 1, then 1 can be used 10 times)
// L - Average length of the combination. Copying a vector to another is an O(N) operation
// N - No. of possible combinations. 