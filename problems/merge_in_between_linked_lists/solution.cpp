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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* current = list1;
        int count = 0;
        ListNode* point1 = nullptr;
        ListNode* point2 = nullptr;
        while(current){
            if(point1 && point2) break;
            if(count == a - 1){
                point1 = current;
            }
            if(count == b + 1){
                point2 = current;
            }
            count++;
            current = current -> next;
        }

        ListNode* current2 = list2;
        while(current2 -> next){
            current2 = current2 -> next;
        }

        point1 -> next = list2;
        current2 -> next = point2;

        return list1;
    }
};