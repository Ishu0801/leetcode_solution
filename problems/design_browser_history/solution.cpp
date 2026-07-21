class BrowserHistory {
private:
    struct Node{
        string value;
        Node* next;
        Node* prev;

        Node(string x){
            value = x;
            next = nullptr;
            prev = nullptr;
        }
    };

    Node* current;

public:
    BrowserHistory(string homepage) {
        current = new Node(homepage);
    }
    
    void visit(string url) {
        Node* newNode = new Node(url);
        current -> next = newNode;
        newNode -> prev = current;
        current = newNode;
        return;
    }
    
    string back(int steps) {
        for(size_t i = 0;i < steps;i++){
            if(current -> prev == nullptr){
                return current -> value;
            }
            current = current -> prev;
        }
        return current -> value;
    }
    
    string forward(int steps) {
        for(size_t i = 0;i < steps;i++){
            if(current -> next == nullptr){
                return current -> value;
            }
            current = current -> next;
        }
        return current -> value;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */