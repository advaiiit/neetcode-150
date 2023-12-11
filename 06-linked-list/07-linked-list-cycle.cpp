#include<unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool usingMap(ListNode *head) {
        unordered_map<ListNode*, int> nodeFreqMap;

        while (head) {
            if (nodeFreqMap[head]) 
                return true;
            else {
                nodeFreqMap[head]++;
                head = head->next;
            }
        }
        return false;
    }
    // TC: O(N) SC: O(N)

    bool fastAndSlow(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while (head && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
    // TC: O(N) SC: O(1)
};