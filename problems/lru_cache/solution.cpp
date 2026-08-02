class LRUCache {
private:
    struct Node{
        pair<int,int> data;
        Node* next;
        Node* prev;

        Node(int key, int val){
            data.first = key;
            data.second = val;
            next = nullptr;
            prev = nullptr;
        }
    };

    int cap;
    unordered_map<int,Node*> mpp;
    int num_of_nodes;
    Node dummy;
    Node* last;

    void insert_at_tail(Node* node){
        if(node -> prev) node -> prev -> next = node -> next;
        if(node ->next) node -> next -> prev = node -> prev;
        last -> next = node;
        node -> prev = last;
        last = node;
        last -> next = nullptr;
    }

    void del_a_node(Node* node){
        node -> prev -> next = node -> next;
        if(node -> next) node -> next -> prev = node -> prev;
        else{last = node -> prev;}
        delete(node);
    }

public:
    LRUCache(int capacity) : dummy(-1,-1){
        cap = capacity;
        mpp.reserve(cap);
        num_of_nodes = 0;
        last = &dummy;
    }
    
    int get(int key) {
        if(num_of_nodes == 0) return -1;
        auto it = mpp.find(key);
        if(it == mpp.end()) return -1;
        Node* node = it -> second;
        if(node == last) return (node -> data).second;
        insert_at_tail(node);
        return (node -> data).second;
    }
    
    void put(int key, int value) {
        auto it = mpp.find(key);
        if(it != mpp.end()){
            Node* node = it -> second;
           (node -> data).second = value;
           if(node == last) return;
           insert_at_tail(node);
           return;
        }
        if(num_of_nodes == cap){
            Node* head = &dummy;
            head = head -> next;
            mpp.erase((head -> data).first);
            del_a_node(head);
            num_of_nodes--;
        }
        Node* newNode = new Node(key,value);
        insert_at_tail(newNode);
        mpp[key] = newNode;
        num_of_nodes++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */