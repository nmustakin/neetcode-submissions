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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr; 
        //minHeap to track the min value
        auto cmp = [](ListNode* a, ListNode* b) {return a->val > b->val; }; 
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp); 
        //insert first of each 
        for(ListNode* first: lists){
            if(first) minHeap.push(first);
        }
        ListNode* res = new ListNode(0);
        ListNode* curr = res;
        while(!minHeap.empty()){
            ListNode* node = minHeap.top();
            minHeap.pop(); 
            curr->next = node; 
            curr = curr->next; 
            if(node->next) minHeap.push(node->next); 
        }

        return res->next; 
    }
};
