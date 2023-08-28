#include<string>
#include<vector>
#include<stack>
#include<unordered_set>
using namespace std;

class GeneratingAllPermutations {
public:
    vector<string> generateParentheses(int n) {
        string baseString = "";
        unordered_set<string> uniqueParentheses;

        for (int i = 0; i < n; i++) baseString += "()";

        sort(baseString.begin(), baseString.end());

        do {
            if (isValidParentheses(baseString)) 
                uniqueParentheses.insert(baseString);
        } while(next_permutation(baseString.begin(), baseString.end()));

        return vector<string> (uniqueParentheses.begin(), uniqueParentheses.end());
    }

    bool isValidParentheses(string baseString) {
        stack<char> stack;

        for (char c : baseString) {
            if (!stack.empty() && c == ')' && stack.top() == '(')
                stack.pop();
            else 
                stack.push(c);
        }

        return stack.empty();
    }
};
// TC: O(N * N!) SC: O(N)

class Backtracking {
public:
    vector<string> generateParenthesis(int n) {
        string baseString = "";
        vector<string> validParentheses;

        generateAllParentheses(n * 2, baseString, validParentheses);

        return validParentheses;
    }

    void generateAllParentheses(int strLen, string baseString, vector<string> &validParentheses) {
        if (strLen == 0) {
            if (isValidParentheses(baseString)) 
                validParentheses.push_back(baseString);
            return;
        }
        
        baseString += "(";
        generateAllParentheses(strLen - 1, baseString, validParentheses);
        
        baseString.pop_back();

        baseString += ")";
        generateAllParentheses(strLen - 1, baseString, validParentheses);
    }

    bool isValidParentheses(string baseString) {
        stack<char> stack;

        for (char c : baseString) {
            if (!stack.empty() && c == ')' && stack.top() == '(')
                stack.pop();
            else 
                stack.push(c);
        }

        return stack.empty();
    }
};
// TC: O(2^N * N) SC: O(N)

class BacktrackingWithoutStack{
public:
    vector<string> generateParenthesis(int n) {
        vector<string> validParentheses;

        generateValidParentheses(n, n, "", validParentheses);

        return validParentheses;
    }

    void generateValidParentheses(int open, int close, string baseString,
        vector<string> &validParentheses) {
        if (open == 0 && close == 0) 
            validParentheses.push_back(baseString);
        
        if (open > 0) 
            generateValidParentheses(open - 1, close, baseString + '(', validParentheses);
        

        if (close > 0 && close > open) 
            generateValidParentheses(open, close - 1, baseString + ')', validParentheses);
    }
};
// TC: O(2^N) SC: O(N)
