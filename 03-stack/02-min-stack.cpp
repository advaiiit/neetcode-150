#include<stack>
using namespace std;

class TwoStacks {
public:
    stack<int> stack, minStack;

    TwoStacks() {
    }
    
    void push(int val) {
        if (minStack.empty() || val <= minStack.top()) 
            minStack.push(val);
        
        stack.push(val);
    }
    
    void pop() {
        if (stack.top() == minStack.top()) 
            minStack.pop();

        stack.pop();   
    }
    
    int top() {
        return stack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
// TC: O(1) SC: O(N)

class StackWithPair {
public:
    stack<pair<int, int>> stackPair;

    StackWithPair() {
    }
    
    void push(int val) {
        if (stackPair.empty() || val <= stackPair.top().second)    
            stackPair.push({val, val});
        else {
            int currMin = stackPair.top().second;
            stackPair.push({val, currMin});
        }
    }
    
    void pop() {
        stackPair.pop();
    }
    
    int top() {
        return stackPair.top().first;
    }
    
    int getMin() {
        return stackPair.top().second;
    }
};
// TC: O(1) SC: O(N)