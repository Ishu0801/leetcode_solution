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
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast -> next && fast -> next -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }

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
    int pairSum(ListNode* head) {
        int max_sum = INT_MIN;
        ListNode* prev = mid_finder(head);
        ListNode* pivot = prev -> next;
        prev -> next = nullptr;
        ListNode* newpivot = reverse(pivot);
        ListNode* sec = newpivot;
        ListNode* first = head;
        int sum = 0;
        while(first){
            sum = first -> val + sec -> val;
            max_sum = max(sum,max_sum);
            first = first -> next;
            sec = sec -> next;
        }
        // prev -> next = nullptr;
        // reverse(newpivot);
        // prev -> next = pivot;
        return max_sum;
    }
};