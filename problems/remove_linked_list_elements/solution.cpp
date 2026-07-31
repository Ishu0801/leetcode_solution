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
    ListNode* removeElements(ListNode* head, int x) {
        if(!head) return head;
        ListNode* current = head;
        ListNode* prev = nullptr;
        while(current){
            ListNode* nextNode = current -> next;
            if(current -> val == x){
                if(prev) prev -> next = nextNode;
                else{head = nextNode;}
                current -> next = nullptr;
                current = nextNode;
                continue;
            }
            prev = current;
            current = nextNode;
        }
        return head;
    }
};