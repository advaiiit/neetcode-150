#include<vector>
#include<unordered_set>
#include<string>
using namespace std;

class Brute {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') continue;
                if (!validSudoku(row, col, board)) 
                    return false;
            }
        }

        return true;
    }

    bool validSudoku(int row, int col, vector<vector<char>> board) {
        char value = board[row][col];

        for (int i = 0; i < 9; i++) {
            if (i != col && board[row][i] == value) 
                return false;
            if (i != row && board[i][col] == value) 
                return false;

            int x = 3 * (row / 3) + i / 3;
            int y = 3 * (col / 3) + i % 3;

            if (x != row && y != col && board[x][y] == value)
                return false;
        }
        return true;
    }
};
// TC: O(N^3) SC: O(1)

class Solution {
public:
    bool usingSet(vector<vector<char>>& board) {
        unordered_set<string> set;
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                string value = to_string(board[i][j]);

                string row = value + "ROW" + to_string(i);
                string col = value + "COL" + to_string(j);
                string box = value + "BOX" + to_string(i / 3) + to_string(j / 3);

                if (set.find(row) != set.end() || set.find(col) != set.end() || set.find(box) != set.end())
                    return false;
                
                set.insert(row);
                set.insert(col);
                set.insert(box);
            }
        }

        return true;
    }
    // TC: O(N^2) SC: O(N)
};