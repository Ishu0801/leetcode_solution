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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        if(!head || !head -> next) return head;
        ListNode* current = head;
        ListNode* first_end = nullptr;
        int count_of_nodes = 1;
        while(current != nullptr && count_of_nodes < left){
            count_of_nodes++;
            first_end = current;
            current = current -> next;
        }
        ListNode* prev = nullptr;
        ListNode* start = current;
        while(current != nullptr && count_of_nodes <= right){
            ListNode* nextNode = current -> next;
            current -> next = prev;
            prev = current;
            current = nextNode;
            count_of_nodes++;
        }
        if(first_end != nullptr){
            first_end -> next = prev;
        }
        start -> next = current;
        return (start == head)?prev : head;
    }
};