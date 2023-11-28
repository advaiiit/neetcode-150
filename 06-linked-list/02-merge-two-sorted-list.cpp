#include<algorithm>
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
    ListNode* usingExtraSpace(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* ptr = head;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                ptr->next = new ListNode(list1->val);
                list1 = list1->next;
            } else {
                ptr->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            ptr = ptr->next;
        }

        while (list1) {
            ptr->next = new ListNode(list1->val);
            list1 = list1->next;
            ptr = ptr->next;
        }

        while (list2) {
            ptr->next = new ListNode(list2->val);
            list2 = list2->next;
            ptr = ptr->next;
        }

        return head->next;
    }
    // TC: O(n1 + n2) SC: O(n1 + n2)

    ListNode* usingTwoPointers(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* ptr = head;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                ptr->next = list1;
                list1 = list1->next;
            } else {
                ptr->next = list2;
                list2 = list2->next;
            }
            
            ptr = ptr->next;
        }

        ptr->next = (list1) ? list1 : list2;

        return head->next;
    }
    // TC: O(n1 + n2) SC: O(1)
    

    ListNode* inPlace(ListNode* list1, ListNode* list2) {
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;

        if (list1->val > list2->val) swap(list1, list2);
        ListNode* head = list1;

        while (list1 && list2) {
            ListNode* temp = new ListNode;
            
            while (list1 && list1->val <= list2->val) {
                temp = list1;
                list1 = list1->next;
            }

            temp->next = list2;
            swap(list1, list2);
        }

        return head;
    }
    // TC: O(n1 + n2) SC: O(1)
};