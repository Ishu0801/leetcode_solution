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
    void deleteNode(ListNode* node) {
        ListNode* current = node;
        ListNode* nextNode = current -> next;
        while(nextNode){
            current -> val = nextNode -> val;
            if(!nextNode -> next){
                current -> next = nullptr;
                delete(nextNode);
                break;
            }
            current = nextNode;
            nextNode = nextNode -> next;
        }
    }
};