#include<stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void usingExtraSpace(ListNode* head) {
        if (!head || !head->next) return;

        ListNode* ptr = head;
        stack<ListNode*> nodeStack;
        
        while(ptr) {
            nodeStack.push(ptr);
            ptr = ptr->next;
        }

        ptr = head;
        ListNode* next = ptr->next;
        while(next != nodeStack.top()) {
            ListNode* last = nodeStack.top();
            nodeStack.pop();
            ptr->next = last;
            last->next = next;

            if (next == nodeStack.top()) 
                break;

            ptr = next;
            next = ptr->next;
        }
        next->next = NULL;
    }
    // TC: O(N + N/2) SC: O(N)
};

class OptimalSolution {
public:
    void withoutExtraSpace(ListNode* head) {
        if (!head || !head->next) return;
        
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* middle = reverse(slow->next);
        slow->next = NULL;

        ListNode* curr = head;
        while (curr && middle) {
            ListNode* currNext = curr->next;
            ListNode* middleNext = middle->next;

            curr->next = middle;
            middle->next = currNext;

            curr = currNext;
            middle = middleNext;
        }
    }

private: 
    ListNode* reverse(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* prev = NULL;
        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};
// TC: O(N + N/2) SC: O(1)
