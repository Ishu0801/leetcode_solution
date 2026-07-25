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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1 || !head -> next) return head;
        ListNode* current = head;
        ListNode* start = head;
        ListNode* last_end = nullptr;
        ListNode* newhead = nullptr;
        int count = 1;
        while(current){
            ListNode* nextNode = current -> next;
            if(count == k){
                current -> next = nullptr;
                ListNode* temp = reverse(start);
                if(last_end == nullptr){
                    newhead = temp;
                }
                else{
                    last_end -> next = temp;
                }
                last_end = start;
                start = nextNode;
                count = 0;
            }
            count++;
            current = nextNode;
        }
        if(start){
            last_end -> next = start;
        }
        return newhead;
    }
};