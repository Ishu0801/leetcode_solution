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
        ListNode* dummy = new ListNode(-1);
        ListNode* current = head;
        while(current){
            ListNode* nextNode = current -> next;
            current -> next = dummy -> next;
            dummy -> next = current;
            current = nextNode;
        }
        head = dummy -> next;
        delete(dummy);
        return head;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        ListNode* newhead = reverse(head);
        ListNode* current = newhead;
        ListNode* prev = nullptr;
        int carry = 0;
        int mult = 0;
        while(current){
            mult = ((current -> val * 2) + carry);
            carry = mult / 10;
            mult = mult % 10;
            current -> val = mult;
            prev = current;
            current = current -> next;
        }
        if(carry != 0){
            ListNode* newNode = new ListNode(carry);
            prev -> next = newNode;
        }
        return reverse(newhead);
    }
};