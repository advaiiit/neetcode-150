#include<vector>
#include<set>
using namespace std;

class BruteSolution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> combination;
        set<vector<int>> uniqueCombinations;

        sort(candidates.begin(), candidates.end());
        findUniqueCombinations(0, target, candidates, combination, uniqueCombinations);

        vector<vector<int>> result(uniqueCombinations.begin(), uniqueCombinations.end());
        return result;
    }

    void findUniqueCombinations(int index, int target, vector<int> candidates,
     vector<int>& combination, set<vector<int>>& uniqueCombinations) {
        if (index == candidates.size()) {
            if (target == 0) {
                uniqueCombinations.insert(combination);
            }
            return;
        }
        int pick = candidates[index];
        combination.push_back(pick);
        findUniqueCombinations(index + 1, target - pick, candidates, combination, uniqueCombinations);
        combination.pop_back();
        findUniqueCombinations(index + 1, target, candidates, combination, uniqueCombinations);

        return;
     }
};
// TC: O(NlogN + 2^N * NlogN) // Initial sorting + Total subsequences * Set Insertion
// SC: O(N + 2^N) // Recursion Stack + Set

class OptimalSolution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> combination;
        vector<vector<int>> uniqueCombinations;

        sort(candidates.begin(), candidates.end());
        findUniqueCombinations(0, target, candidates, combination, uniqueCombinations);

        return uniqueCombinations;
    }

    void findUniqueCombinations(int index, int target, vector<int> candidates,
     vector<int>& combination, vector<vector<int>>& uniqueCombinations) {
        if (target == 0) {
            uniqueCombinations.push_back(combination);
            return;
        }
    
        for (int i = index; i < candidates.size(); i++) {
            int pick = candidates[i];
            if (i > index && pick == candidates[i-1]) {
                continue;
            }
            if (pick > target) {
                break;
            }
            combination.push_back(pick);
            findUniqueCombinations(i + 1, target - pick, candidates, combination, uniqueCombinations);
            combination.pop_back();
        }
     }
};
// TC: O(2^N * K) K: Avg. length of combination
// SC: O(K * X) X: Total combinations