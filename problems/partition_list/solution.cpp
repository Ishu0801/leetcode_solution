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
private:
    void insert_at_head(ListNode* head,ListNode* node,ListNode* prev){
        prev -> next = node -> next;
        node -> next = head;
    }

public:
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head -> next) return head;
        ListNode* current = head;
        ListNode* prev = nullptr;
        ListNode dummy(-1);
        ListNode* dum_curr = &dummy;
        while(current){
            ListNode* nextNode = current -> next;
            if(current -> val < x){
                if(prev)prev -> next = current -> next;
                else {head = current -> next;}
                dum_curr -> next = current;
                current -> next = nullptr;
                dum_curr = dum_curr -> next;
                current = nextNode;
                continue;
            }
            prev = current;
            current = nextNode;
        }
        dum_curr -> next = head;
        return dummy.next;
    }
};