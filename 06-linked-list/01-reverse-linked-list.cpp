#include<vector>
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
    ListNode* usingExtraSpace(ListNode* head) {
        vector<int> values;
        ListNode* temp = head;

        while(temp) {
            values.push_back(temp->val);
            temp = temp->next;
        }

        temp = head;
        for (int i = values.size() - 1; i >= 0; i--) {
            temp->val = values[i];
            temp = temp->next;
        }

        return head;
    }
    // TC: O(N) SC: O(N)

    ListNode* recursive(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* newHead = recursive(head->next);
        head->next->next = head;
        head->next = NULL;

        return newHead;
    }
    // TC: O(N) SC: O(N)

    ListNode* iterative(ListNode* head) {
        ListNode* prev = NULL;

        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }
    // TC: O(N) SC: O(1)
};