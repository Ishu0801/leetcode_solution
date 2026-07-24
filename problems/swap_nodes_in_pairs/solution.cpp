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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head -> next) return head;
        ListNode* back = head;
        ListNode* front = head -> next;
        ListNode* last_end = nullptr;
        head = front;
        while(back &&  front){
            ListNode* temp = front -> next;
            front -> next = back;
            back -> next = nullptr;

            if(last_end){
                last_end -> next = front;
            }
            last_end = back;
            back = temp;
            if(back){
                front = back -> next;
            }
        }
        if(back){
            last_end -> next = back;
        }
        return head;
    }
};