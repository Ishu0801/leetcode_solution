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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head -> next) return head;
        ListNode* prev_back = nullptr;
        ListNode* back = head;
        ListNode* front = head -> next;
        while(front){
            ListNode* nextNode = front -> next;
            if(back -> val == front -> val){
                back -> next = nextNode;
                delete(front);
                front = nextNode;
                if(front != nullptr && back -> val != front -> val){
                    if(prev_back) prev_back -> next = front;
                    else{head = front;}
                    delete(back);
                    back = front;
                    front = front -> next;
                }
                else if(front == nullptr){
                    if(prev_back) prev_back -> next = nullptr;
                    else{head = nullptr;}
                    delete(back);
                }
            }
            else{
                prev_back = back;
                back = front;
                front = nextNode;
            }
        }
        return head;
    }
};