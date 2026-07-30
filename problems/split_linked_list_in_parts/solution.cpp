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
    int length_finder(ListNode* head){
        int count = 0;
        ListNode* current = head;
        while(current){
            count++;
            current = current -> next;
        }
        return count;
    }
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        if(!head){
            return vector<ListNode*>(k,nullptr);
        }
        vector<ListNode*> ans;
        int length = length_finder(head);
        int size_per_part = length / k;
        int extra_rem_part = length % k;
        ListNode* current = head;
        while(current){
            ListNode* nextNode = current -> next;
            if(k >= length){
                current -> next = nullptr;
                ans.push_back(current);
                current = nextNode;
                continue;
            }
            ListNode* start = current;
            int count = 1;
            while(nextNode && count != size_per_part){
                count++;
                current = nextNode;
                if(nextNode) nextNode = nextNode -> next;
            }
            if(nextNode && extra_rem_part != 0){
                current = nextNode;
                if(nextNode) nextNode = nextNode -> next;
                extra_rem_part--;
            }
            current -> next = nullptr;
            current = nextNode;
            ans.push_back(start);
        }
        while(ans.size() != k){
            ans.push_back({});
        }
        return ans;
    }
};