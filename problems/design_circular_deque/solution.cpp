class MyCircularDeque {
private:
    struct Node{
        int val;
        Node* next;
        Node* prev;

        Node(int x){
            val = x;
            next = nullptr;
            prev = nullptr;
        }
    };
    int max_size;
    int cur_size = 0;
    Node* dummy = new Node(-1);
    Node* lastNode = dummy;

public:
    MyCircularDeque(int k) {
        this -> max_size = k;
    }
    
    bool insertFront(int value) {
        if(cur_size == max_size) return false;
        Node* newNode = new Node(value);
        if(!dummy -> next){
            lastNode = newNode;
        }
        if(dummy -> next){
            dummy -> next -> prev = newNode;
        }
        newNode -> next = dummy -> next;
        newNode -> prev = dummy;
        dummy -> next = newNode;
        cur_size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(cur_size == max_size) return false;
        Node* newNode = new Node(value);
        lastNode -> next = newNode;
        newNode -> prev = lastNode;
        lastNode = newNode;
        cur_size++;
        return true;
    }
    
    bool deleteFront() {
        if(!dummy -> next) return false;
        if(!dummy -> next -> next){
            lastNode = dummy;
        }
        Node* delNode = dummy -> next;
        dummy -> next = delNode -> next;
        if(delNode-> next){
            delNode -> next -> prev = dummy; 
        }
        cur_size--;
        delete(delNode);
        return true;
    }
    
    bool deleteLast() {
        if(!dummy -> next) return false;
        Node* delNode = lastNode;
        delNode -> prev -> next  = lastNode -> next;
        lastNode = lastNode -> prev;
        delete(delNode);
        cur_size--;
        return true;
    }
    
    int getFront() {
        if(!dummy -> next)return -1;
        return dummy -> next -> val;
    }
    
    int getRear() {
        if(!dummy -> next) return -1;
        return lastNode -> val;
    }
    
    bool isEmpty() {
        return (dummy -> next == nullptr)?true:false;
    }
    
    bool isFull() {
        return cur_size == max_size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */