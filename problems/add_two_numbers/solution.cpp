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
    int counter(ListNode* head){
        ListNode* current = head;
        int count = 0;
        while(current){
            count++;
            current = current -> next;
        }
        return count;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int l1_size = counter(l1);
        int l2_size = counter(l2);
        if(l1_size < l2_size){
            return addTwoNumbers(l2,l1);
        }
        ListNode* current1 = l1;
        if(l1_size == 1 && l1 -> val == 0) return l2;
        ListNode* current2 = l2;
        if(l2_size == 1 && l2 -> val == 0) return l1;
        ListNode* prev = nullptr;
        int carry = 0;
        while(current1 != nullptr && current2 != nullptr){
            ListNode* nextNode1 = current1 -> next;
            ListNode* nextNode2 = current2 -> next;
            prev = current1;
            int sum = (current1 -> val) + (current2 -> val) + (carry);
            carry = sum / 10;
            sum = sum % 10;
            current1 -> val = sum;
            current1 = nextNode1;
            current2 = nextNode2;
        }

        while(carry != 0){
            if(current1 == nullptr){
                prev -> next = new ListNode(carry);
                carry = 0;
            }
            else{
                ListNode* nextNode = current1 -> next;
                prev = current1;
                int sum = (current1 -> val) + carry;
                carry = sum / 10;
                sum = sum % 10;
                current1 -> val = sum;
                current1 = nextNode;
            }
        }
        return l1;
    }
};