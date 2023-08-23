#include<vector>
using namespace std;

class Solution {
public:
    vector<int> prefixAndSuffixArrays(vector<int>& nums) {
        int totalNums = nums.size();
        vector<int> res(totalNums), prefix(totalNums), suffix(totalNums);

        prefix[0] = 1;
        for (int i = 1; i < totalNums; i++) 
            prefix[i] = prefix[i - 1] * nums[i - 1];
        
        suffix[totalNums - 1] = 1;
        for (int i = totalNums - 2; i >= 0; i--) 
            suffix[i] = suffix[i + 1] * nums[i + 1];
        

        for (int i = 0; i < totalNums; i++) 
            res[i] = prefix[i] * suffix[i];

        return res;
    }
    // TC: O(N) SC: O(N)

    vector<int> computingPrefixAndSuffixInOneLoop(vector<int>& nums) {
        int totalNums = nums.size();
        vector<int> res(totalNums), prefix(totalNums), suffix(totalNums);

        int productFromStart = 1, productFromEnd = 1;

        for (int i = 0; i < totalNums; i++) {
            int endIndex = totalNums - i - 1;

            prefix[i] = productFromStart;
            suffix[endIndex] = productFromEnd;

            productFromStart *= nums[i];
            productFromEnd *= nums[endIndex]; 
        }

        for (int i = 0; i < totalNums; i++) 
            res[i] = prefix[i] * suffix[i];
    }
    // TC: O(N) SC: O(N)
    // If you observe above code, you can notice that storing all 
    // prefixes and suffixes is not required

       vector<int> withoutExtraSpace(vector<int>& nums) {
        int totalNums = nums.size();
        vector<int> res(totalNums, 1);
 
        for (int i = 0, prefix = 1, suffix = 1; i < totalNums; i++) {
            int endIndex = totalNums - i - 1;

            res[i] *= prefix;
            res[endIndex] *= suffix;

            prefix *= nums[i];
            suffix *= nums[endIndex]; 
        }

        return res;
    }
    // TC: O(N) SC: O(1)
};