/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        bool loop_exists = false;
        while(fast ->  next && fast -> next -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast){
                loop_exists = true;
                break;
            }
        }

        if(loop_exists == false) return nullptr;

        slow = head;
        while(slow != fast){
            slow = slow -> next;
            fast = fast -> next;
        }
        return slow;
    }
};