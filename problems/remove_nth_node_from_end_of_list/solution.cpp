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

    int length(ListNode* head){
        int count = 0;
        ListNode *current = head;
        while(current){
            count++;
            current = current -> next;
        }
        return count;
    }

    ListNode* Node_deleter(ListNode* head,int position){
        ListNode* current = head;
        ListNode* prev = nullptr;
        int i = 1;
        if(position == 1){
            head = head -> next;
            return head;
        }
        while(current != nullptr && i < position){
            ListNode* nextNode = current -> next;
            prev = current;
            current = nextNode;
            i++;
        }
        if(i != position){
            return nullptr;
        }
        prev -> next = current -> next;
        delete(current);
        return head;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int total_nodes = length(head);
        int position_from_front = (total_nodes - n) + 1;
        return Node_deleter(head,position_from_front);
    }
};