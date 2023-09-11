#include<vector>
using namespace std;

class Solution {
public:
    bool searchMatrix1(vector<vector<int>>& matrix, int target) {
        int numRows = matrix.size(), numCols = matrix[0].size();
        int start = 0, end = numRows- 1;
        int row = 0;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (matrix[mid][0] <= target) {
                row = mid;
                start++;
            } else 
                end--;
        }

        start = 0; end = numCols - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (matrix[row][mid] == target)
                return true;
            else if (matrix[row][mid] < target)
                start++;
            else
                end--;
        }

        return false;
    }
    // TC: O(log(N * M)) SC: O(1)

    bool searchMatrix2(vector<vector<int>>& matrix, int target) {
        int numRows = matrix.size(), numCols = matrix[0].size();
        int start = 0, end = numRows * numCols - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            int curr = matrix[mid / numCols][mid % numCols];

            if (curr == target) 
                return true;
            else if (curr < target) 
                start++;
            else 
                end--;
        }

        return false;
    }
    // TC: O(log(N * M)) SC: O(1)
};