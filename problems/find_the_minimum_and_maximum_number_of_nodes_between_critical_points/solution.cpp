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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int farest_node = -1;
        int nearest_node = INT_MAX;
        int prev_farest = -1;
        int count = 2;
        ListNode* prev = head;
        ListNode* current = head -> next;
        int min_distance = INT_MAX;
        while(current -> next){
            ListNode* nextNode = current -> next;
            if(((current -> val < prev -> val) && (current -> val < nextNode -> val)) || ((current -> val > prev -> val) && (current -> val > nextNode -> val))){
                prev_farest = farest_node;
                farest_node = max(farest_node,count);
                nearest_node = min(nearest_node,count);
                if(prev_farest != -1){
                    int distance = farest_node - prev_farest;
                    min_distance = min(min_distance,distance);
                }
            }
            count++;
            prev = current;
            current = nextNode;
        }
        if(farest_node == -1 || prev_farest == -1 || nearest_node == INT_MAX){
            return {-1,-1};
        }

        int max_distance = farest_node - nearest_node;
        return {min_distance,max_distance};

    }
};