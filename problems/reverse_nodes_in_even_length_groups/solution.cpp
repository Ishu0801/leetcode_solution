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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        if(!head -> next || !head -> next -> next) return head;
        ListNode* current = head -> next;
        ListNode* last_end = head;
        int len = 2;
        while(current){
            int current_len = 1;
            ListNode* sub_head = current;
            ListNode* nextNode = current -> next;
            while(nextNode && current_len != len){
                current_len++;
                current = nextNode;
                if(nextNode) nextNode = nextNode -> next;
            }
            if((current) && current_len % 2 == 0){
                last_end -> next = nullptr;
                current -> next = nullptr;
                ListNode* reversed_head = reverse(sub_head);
                last_end -> next = reversed_head;
                sub_head -> next = nextNode;
                last_end = sub_head;
                current = nextNode;
                len = len + 1;
                continue;
            }
            last_end = current;
            current = nextNode;
            len = len + 1;
        }
        return head;
    }
};