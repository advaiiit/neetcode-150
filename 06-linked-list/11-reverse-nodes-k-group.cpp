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
    ListNode* brute(ListNode* head, int k) {
        ListNode* ptr = head;
        vector<vector<int>> listValues;
        int i = 0;
        
        while (ptr) {
            vector<int> temp;
            while (ptr && i < k) {
                temp.push_back(ptr->val);
                ptr = ptr->next;
                i++;
            }
            if (i == k) reverse(temp.begin(), temp.end());
            listValues.push_back(temp);
            i = 0;
        }

        vector<int> flattened;
        for (vector<int> row : listValues) {
            for (int val : row) {
                flattened.push_back(val);
            }
        }

        i = 0;
        ptr = head;
        while (ptr) {
            ptr->val = flattened[i++];
            ptr = ptr->next;
        }

        return head;
    }
    // TC: O(3N) SC: (2N)

    ListNode* optimal(ListNode* head, int k) {
        
        // For each group, you need to reverse k-1 links
        // Reverse each link for a group one by one
        // After k-1 reverse operations move to the next group

        if (k == 1) return head;

        int listSize = getListSize(head);
        if (listSize == 1) return head;

        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;

        while (listSize >= k) {
            ListNode* curr = prev->next;
            ListNode* next = curr->next;

            for (int i = 0; i < k - 1; i++) {
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            }

            listSize -= k;
            prev = curr;
        }

        return dummy->next;
    }

    int getListSize(ListNode* head) {
        int i = 0;

        while (head) {
            head = head->next;
            i++;
        }
        
        return i;
    }
};