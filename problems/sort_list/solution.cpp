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
    ListNode* mid_spliter(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head -> next;
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode* mid = slow -> next;
        slow -> next = nullptr;
        return mid;
    }

    ListNode* merger(ListNode* first_sorted_part,ListNode* second_sorted_part){
        ListNode dummy(-1);
        ListNode* current = &dummy;
        ListNode* left = first_sorted_part;
        ListNode* right = second_sorted_part;
        while(left && right){
            if(left -> val < right -> val){
                current -> next = left;
                left = left -> next;
            }
            else{
                current -> next = right;
                right = right -> next;
            }
            current = current -> next;
        }

        current -> next = left ? left : right;
        return dummy.next;
    }

public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head -> next) return head;
        ListNode*mid = mid_spliter(head);

        ListNode* first_sorted_part = sortList(head);
        ListNode* second_sorted_part = sortList(mid);

        return merger(first_sorted_part,second_sorted_part);
    }
};