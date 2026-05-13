/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return head; 
        ListNode* current = head;
        ListNode* nxt = current->next; 
        while(nxt != nullptr){
            ListNode* rest = nxt->next;
            nxt->next = current;
            current = nxt; 
            nxt = rest; 
        }
        head->next = nullptr; 
        head = current; 

        return head; 
    }
};
