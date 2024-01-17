#include<unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* Brute(Node* head) {
        if (!head) return NULL;

        unordered_map<Node*, Node*> deepCopy;
        Node* ptr = head;

        while (ptr) {
            deepCopy.insert({ptr, new Node(ptr->val)});
            ptr = ptr->next;
        }

        ptr = head;
        while (ptr) {
            deepCopy[ptr]->next = deepCopy[ptr->next];
            deepCopy[ptr]->random = deepCopy[ptr->random];
            ptr = ptr->next;
        }

        return deepCopy[head];
    }
    // TC: O(2N) SC: O(N)

    Node* optimal(Node* head) {
        Node* originalHead = head;

        // 1. Create copy nodes adjacent to orginal node
        while (head) {
            Node* headCopy = new Node(head->val);
            headCopy->next = head->next;
            head->next = headCopy;
            head = headCopy->next;
        }

        // 2. Copy the random pointer
        head = originalHead;
        while(head) {
            head->next->random = (head->random)? head->random->next : NULL;
            head = head->next->next;
        }

        head = originalHead;
        Node* newHead = new Node(0);
        Node* ptr = newHead;

        // 3. Restore original list
        while (head) {
            ptr->next = head->next;
            ptr = ptr->next;

            head->next = head->next->next;
            head = head->next;
        }

        return newHead->next;
    }
    // TC: O(3N) SC: O(1)
};