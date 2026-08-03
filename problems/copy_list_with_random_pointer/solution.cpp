/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node* current = head;
        while(current){
            Node* nextNode = current -> next;
            Node* copyNode = new Node(current -> val);
            current -> next = copyNode;
            copyNode -> next = nextNode;
            current = nextNode;
        }

        Node* ori_curr = head;
        Node* copy_curr = head -> next;
        while(ori_curr || copy_curr){
            if(ori_curr -> random) copy_curr -> random = ori_curr -> random -> next;
            ori_curr = ori_curr -> next -> next;
            if(copy_curr -> next == nullptr) copy_curr = copy_curr -> next;
            else copy_curr = copy_curr -> next -> next;
        }

        Node* copied_node = head -> next;
        Node* original_node = head;
        Node dummy(-1);
        Node* dum_curr = &dummy;
        while(copied_node){
            original_node -> next = copied_node -> next;
            dum_curr -> next = copied_node;
            original_node = original_node -> next;
            if(copied_node -> next == nullptr) copied_node = copied_node -> next;
            else copied_node = copied_node -> next -> next;
            dum_curr = dum_curr -> next;
        }
        return dummy.next;
    }
};