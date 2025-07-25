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

using p = pair<int, ListNode*>; 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<p, vector<p>, greater<p>> pq;
        for(auto head : lists) if(head) pq.push({head -> val, head});

    ListNode* ans_head = new ListNode(-1);
    ListNode* tail = ans_head;

        while(pq.size()){
            auto [val, it] = pq.top(); pq.pop();
            tail -> next = it;
            tail = it;
            it = it -> next;
            tail -> next = NULL;
            if(it) pq.push({it -> val, it});
        }

        return ans_head -> next;
    }
};

// Just took min and pop out to take next one if exists becz this si how current next is explored and 
// next smallest will be in remainning and next of the chosen one - using PQ perfectly fot this 