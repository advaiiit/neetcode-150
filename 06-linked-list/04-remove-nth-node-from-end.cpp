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
    ListNode* twoPass(ListNode* head, int n) {
        int size = 0;
        int posFromStart;
        ListNode* ptr = head;

        while (ptr) {
            ptr = ptr->next;
            size++;
        }
        posFromStart = size - n;

        if (n == size) return head->next;

        ptr = head;
        while (--posFromStart) ptr = ptr->next;
        ptr->next = ptr->next->next;

        return head;
    }
    // TC: O(2N) SC: O(1)

    ListNode* fastNSlowPtrs(ListNode* head, int n) {
        int pos = n;
        ListNode* fast = head;
        ListNode* slow = head;

        while (pos--) fast = fast->next;

        if (!fast) return slow->next;
        
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        
        return head;
    }
    // TC: O(N) SC: O(1)
};

