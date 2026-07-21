class MyLinkedList {
private:
    ListNode* head;
    ListNode* tail;
public:
    MyLinkedList() {
        head = nullptr;
    }
    
    int get(int index) {
        ListNode* current = head;
        int cur_ind = 0;
        while(current != nullptr){
            if(cur_ind == index){
                return current -> val;
            }
            current = current -> next;
            cur_ind++;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        if(head == nullptr){
            head = newNode;
            tail = newNode;
            return;
        }
        newNode -> next = head;
        head = newNode;
    }
    
    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        if(head == nullptr){
            head = newNode;
            tail = newNode;
            return;
        }
        tail -> next = newNode;
        tail = newNode;
    }
    
    void addAtIndex(int index, int val) {
        ListNode* newNode = new ListNode(val);
        ListNode* current = head;
        ListNode* prev = nullptr;
        int inx = 0;
        if(index == 0){
            delete(newNode);
            addAtHead(val);
            return;
        }
        while(current){
            if(inx == index){
                if(!prev){
                    delete(newNode);
                    addAtHead(val);
                    return;
                }
                prev -> next = newNode;
                newNode ->next = current;
                return;
            }
            prev = current;
            current = current -> next;
            inx++;
        }
        if(inx == index){
            delete(newNode);
            addAtTail(val);
        }
        return;
    }
    
    void deleteAtIndex(int index) {
        ListNode* current = head;
        ListNode* prev = nullptr;
        int inx = 0;
        while(current){
            ListNode* nextNode = current -> next;
            if(inx == index){
                if(prev){
                    prev -> next = nextNode;
                    if(nextNode == nullptr){
                        tail = prev;
                    }
                    delete(current);
                    current = nextNode;
                    return;
                }
                head = nextNode;
                if(head == nullptr){
                    tail = nullptr;
                }
                delete(current);
                return;
            }
            prev = current;
            current = nextNode;
            inx++;
        }
        return;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */