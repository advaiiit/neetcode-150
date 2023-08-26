#include<stack>
#include<unordered_set>
#include<string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        unordered_set<string> operators = {"+", "-", "*", "/"};

        for (string token : tokens) {
            if (operators.find(token) != operators.end()) 
                performOperation(token[0], stack);
            else 
                stack.push(stoi(token)); 
        }

        return stack.top();
    }

    void performOperation(char op, stack<int>& stack) {
        int secondOperand = stack.top();
        stack.pop();

        int firstOperand = stack.top();
        stack.pop();

        int result;

        switch(op) {
            case '+':   result = firstOperand + secondOperand;
                        break;
            case '-':   result = firstOperand - secondOperand;
                        break;
            case '*':   result = firstOperand * secondOperand;
                        break;
            case '/':   result = firstOperand / secondOperand;
                        break;
        }

        stack.push(result);
    }    
};

// TC: O(N) SC: O(N)