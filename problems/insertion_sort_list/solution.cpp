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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head -> next) return head;
        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;
        head = head -> next;
        dummy -> next -> next = nullptr; 
        ListNode* current = head;

        while(current){
            ListNode* nextNode = current -> next;
            ListNode* prev = dummy;
            ListNode* dummy_cur = dummy -> next;
            while(dummy_cur && current -> val > dummy_cur -> val){
                prev = dummy_cur;
                dummy_cur = dummy_cur -> next;
            }
            prev -> next = current;
            current -> next = dummy_cur;
            current = nextNode;
        }

        head = dummy -> next;
        delete(dummy);
        return head;
    }
};