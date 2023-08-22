#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    static bool cmp(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }

    vector<int> hashMapAndSorting(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> freqMap;
        vector<pair<int, int>> freqPairs;

        for (int num : nums) freqMap[num]++;

        for (auto it : freqMap) 
            freqPairs.push_back({it.first, it.second});

        sort(freqPairs.begin(), freqPairs.end(), cmp);

        for (int i = 0; i < k; i++)
            res.push_back(freqPairs[i].first);
    
        return res;
    }
    // TC: O(NLogN) SC: O(N) 

    vector<int> bucketSort(vector<int>& nums, int k) {
        int totalNums = nums.size();
        vector<int> res;
        vector<vector<int>> buckets(totalNums + 1);
        unordered_map<int, int> freqMap;
        
        for (int num : nums) freqMap[num]++;

        for (auto it : freqMap) 
            buckets[it.second].push_back(it.first);
        
        for (int i = totalNums; i >= 0 && res.size() < k; i--) {
            if (!buckets[i].empty()) 
                res.insert(res.end(), buckets[i].begin(), buckets[i].end());
        }

        return res;
    }
    // TC: O(N) SC: O(N)
};