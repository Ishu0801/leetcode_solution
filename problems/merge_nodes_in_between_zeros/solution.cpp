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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* current = head -> next;
        ListNode* last_merged = head;
        int sum = 0;
        while(current){
            ListNode* nextNode = current -> next;
            if(current -> val == 0){
                current -> val = sum;
                sum = 0;
                last_merged -> next = current;
                last_merged = current;
            }
            else{
                sum += current -> val;
            }
            current = nextNode;
        }
        return head -> next;
    }
};