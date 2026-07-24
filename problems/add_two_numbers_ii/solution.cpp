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

    int counter(ListNode* head){
        int count = 0;
        ListNode* current = head;
        while(current){
            count++;
            current = current -> next;
        }
        return count;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int size1 = counter(l1);
        int size2 = counter(l2);
        if(size1 < size2){
            return addTwoNumbers(l2,l1);
        }
        ListNode* newhead = reverse(l1);
        ListNode* curr1 = newhead;
        ListNode* curr2 = reverse(l2);
        ListNode* prev = nullptr;
        int carry = 0;
        int sum = 0;
        while(curr1 && curr2){
            sum = curr1 -> val + curr2 -> val + carry;
            carry = sum / 10;
            sum = sum % 10;
            curr1 -> val = sum;
            prev = curr1;
            curr1 = curr1 -> next;
            curr2 = curr2 -> next;
        }
        while(carry != 0){
            if(!curr1){
                ListNode* newNode = new ListNode(carry);
                prev -> next = newNode;
                carry = 0;
                break;
            }
            sum = curr1 -> val + carry;
            carry = sum / 10 ;
            sum = sum % 10;
            curr1 -> val = sum;
            prev = curr1;
            curr1 = curr1 -> next;
        }
        return reverse(newhead);
    }
};