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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head -> next || !head -> next -> next) return head;
        ListNode* dummy_even = new ListNode(-1);
        ListNode* even_cur = dummy_even;
        ListNode* dummy_odd = new ListNode(-1);
        ListNode* odd_curr = dummy_odd;
        ListNode* current = head;
        int count = 1;
        while(current){
            ListNode* nextNode = current -> next;
            if(count % 2 == 0){
                current -> next = nullptr;
                even_cur -> next = current;
                even_cur = current;
            }
            else{
                current -> next = nullptr;
                odd_curr -> next = current; 
                odd_curr = current;
            }
            count++;
            current = nextNode;
        }
        odd_curr -> next = dummy_even -> next;
        delete(dummy_odd);
        delete(dummy_even);
        return head;
    }
};