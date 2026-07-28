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
    ListNode* reverse(ListNode* head){
        ListNode* current = head;
        ListNode* prev = nullptr;
        while(current){
            ListNode* nextNode = current -> next;
            current -> next = prev;
            prev = current;
            current = nextNode;
        }
        return prev;
    }

public:
    ListNode* removeNodes(ListNode* head) {
        if(!head -> next) return head;
        ListNode* newhead = reverse(head);
        int max_val = INT_MIN;
        ListNode* current = newhead;
        ListNode* prev = nullptr;
        while(current){
            ListNode* nextNode = current -> next;
            if(max_val <= current -> val){
                max_val = current -> val;
                prev = current;
                current = nextNode;
                continue;
            }
            if(prev) prev -> next = nextNode;
            current -> next = nullptr;
            current = nextNode;
        }
        return reverse(newhead);
    }
};