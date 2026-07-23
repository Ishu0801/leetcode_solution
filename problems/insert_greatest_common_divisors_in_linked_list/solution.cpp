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
    int gcd_finder(int first,int second){
        int num1 = first;
        int num2 = second;
        if(first < second){
            gcd_finder(second,first);
        }
        int rem = 0;
        while(num2 != 0){
            rem = num1 % num2;
            num1 = num2;
            num2 = rem;
        }
        return num1;
    }

public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* current = head;
        ListNode* nextNode = head -> next;
        while(nextNode){
            int gcd = gcd_finder(current -> val,nextNode -> val);
            ListNode* newNode = new ListNode(gcd);
            current -> next = newNode;
            newNode -> next = nextNode;
            current = nextNode;
            nextNode = nextNode -> next;
        }
        return head;
    }
};