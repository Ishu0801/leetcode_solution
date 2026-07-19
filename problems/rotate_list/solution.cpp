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

    int length_finder(ListNode* head){
        ListNode* current = head;
        int count = 0;
        while(current){
            count++;
            current = current -> next;
        }
        return count;
    }

    ListNode* rotateRight(ListNode* &head, int k) {
        if(!head || !head -> next) return head;
        int length = length_finder(head);
        ListNode* current = head;
        ListNode* newhead = nullptr;
        k = k % length;
        if(k == 0){
            return head;
        }
        int pivot = length - k;
        int count_of_nodes = 0;
        while(current -> next != nullptr){
            ListNode* nextNode = current -> next;
            count_of_nodes++;
            if(count_of_nodes == pivot){
                current -> next = nullptr;
                newhead = nextNode;
            }
            current = nextNode;
        }
        current -> next = head;
        return newhead;
    }
};