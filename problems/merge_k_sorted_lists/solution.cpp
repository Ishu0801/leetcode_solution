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
        if(lists.size() == 0) return nullptr;
        priority_queue<pair<int,ListNode*>> pq;
        for(size_t i = 0;i < lists.size();i++){
            if(lists[i])pq.push({-(lists[i] -> val),lists[i]});
        }
        ListNode dummy(-1);
        ListNode* current = &dummy;
        while(!pq.empty()){
            auto it = pq.top().second;
            pq.pop();
            if(it -> next) pq.push({-(it -> next -> val),it -> next});
            current -> next = it;
            current = current -> next;
        }
        current -> next = nullptr;
        return dummy.next;
    }
};