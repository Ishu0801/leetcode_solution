class MyCircularQueue {
private:
    struct Node{
        int value;
        Node* next;

        Node(int x){
            value = x;
            next = nullptr;
        }
    };

    int num_of_nodes = 0;
    int size;
    Node* head = nullptr;
    Node* tail = nullptr;

public:
    MyCircularQueue(int k) {
        size = k;
    }
    
    bool enQueue(int value) {
        if(num_of_nodes >= size) return false;
        Node* newNode = new Node(value);
        if(head == nullptr){
            head = newNode;
            tail = head;
            num_of_nodes++;
            tail -> next = head;
            return true;
        }
        tail -> next = newNode;
        tail = newNode;
        tail -> next = head;
        num_of_nodes++;
        return true;
    }
    
    bool deQueue() {
        if(head == nullptr) return false;
        Node* current = head;
        if(num_of_nodes == 1){
            head = nullptr;
            tail = nullptr;
            delete(current);
            num_of_nodes--;
            return true;
        }
        head = head -> next;
        delete(current);
        tail -> next = head;
        num_of_nodes--;
        return true;
    }
    
    int Front() {
        if(head == nullptr) return -1;
        return head -> value;
    }
    
    int Rear() {
        if(tail == nullptr) return -1;
        return tail -> value;
    }
    
    bool isEmpty() {
        return head == nullptr;
    }
    
    bool isFull() {
        return num_of_nodes == size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */