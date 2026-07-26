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
    int size_of_LL(ListNode* head){
        int count = 0;
        ListNode* current = head;
        while(current){
            count++;
            current = current -> next;
        }
        return count;
    }
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if(!head -> next)return head;
        int length = size_of_LL(head);
        int k_from_back = (length - k) + 1;
        int count =1;
        ListNode* first_Node = nullptr;
        ListNode* prev1 = nullptr;
        ListNode* sec_Node = nullptr;
        ListNode* prev2 = nullptr;
        ListNode* current = head;
        ListNode* prev = nullptr;
        while(current){
            if(first_Node && sec_Node) break;
            if(count == k){
                first_Node = current;
                prev1 = prev;
            }
            if(count == k_from_back){
                sec_Node = current;
                prev2 = prev;
            }
            count++;
            prev = current;
            current = current -> next;
        }
        if(first_Node == head) head = sec_Node;
        else if(sec_Node == head) head = first_Node;
        if(prev2 != nullptr) prev2 -> next = first_Node;
        if(prev1 != nullptr) prev1 -> next = sec_Node;
        ListNode* temp = first_Node -> next;
        first_Node -> next = sec_Node -> next;
        sec_Node -> next = temp;
        return head;
    }
};