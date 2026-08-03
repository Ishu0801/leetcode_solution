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
    ListNode* mid_finder(ListNode* head){
        if(!head -> next) return head;
        ListNode* slow = head;
        ListNode* fast = head -> next;
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow; 
    }

    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* current = head;
        while(current){
            ListNode* nextNode = current -> next;
            current -> next = prev;
            prev = current;
            current = nextNode;
        }
        return prev;
    }

public:
    void reorderList(ListNode* head) {
        ListNode* mid = mid_finder(head);
        ListNode* newhead = mid -> next;
        mid -> next = nullptr;
        ListNode* reversed_head = reverse(newhead);
        ListNode* curr1 = head;
        ListNode* curr2 = reversed_head;
        while(curr1 && curr2){
            ListNode* nextNode1 = curr1 -> next;
            ListNode* nextNode2 = curr2 -> next;
            curr1 -> next = curr2;
            curr2 -> next = nextNode1;
            curr1 = nextNode1;
            curr2 = nextNode2;
        }
    }
};