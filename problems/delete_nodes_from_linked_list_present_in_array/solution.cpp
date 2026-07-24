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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(),nums.end());
        ListNode* current = head;
        ListNode* prev = nullptr;
        while(current){
            ListNode* nextNode = current -> next;
            if(st.find(current -> val) != st.end()){
                if(prev != nullptr){
                    prev -> next = nextNode;
                }
                else{
                    head = nextNode;
                }
                current -> next = nullptr;
                current = nextNode;
            }
            else{
                prev = current;
                current = nextNode;
            }
        }
        return head;
    }
};