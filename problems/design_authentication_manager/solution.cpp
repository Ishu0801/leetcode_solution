class AuthenticationManager {
private:
struct Node{
    int val;
    string str;
    Node* next;
    Node* prev;

    Node(int x,string s){
        val = x;
        str = s;
        next = nullptr;
        prev = nullptr;
    }
};

unordered_map<string,Node*> mpp;
Node* start = nullptr;
Node* last = start;
int life_of_token;

public:
    AuthenticationManager(int timeToLive) {
        life_of_token = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        if(!start){
            start = new Node(currentTime + life_of_token,tokenId);
            last = start;
            mpp[tokenId] = start;
            return;
        }
        Node* newNode = new Node(currentTime + life_of_token,tokenId);
        last -> next = newNode;
        newNode -> prev = last;
        last = newNode;
        mpp[tokenId] = newNode;
    }
    
    void renew(string tokenId, int currentTime) {
        auto value = mpp.find(tokenId);
        if(value == mpp.end()) return;
        if(value -> second -> val > currentTime){
            value -> second -> val = currentTime + life_of_token;
            if(last == value -> second) return;
            if(value -> second -> prev) value -> second -> prev -> next = value -> second -> next;
            else{start = start -> next;}
            if(value -> second -> next) value -> second -> next -> prev = value -> second -> prev;
            last -> next = value -> second;
            value -> second -> prev = last;
            value -> second -> next = nullptr;
            last = value -> second;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        Node* current = start;
        int size = mpp.size();
        int count = 0;
        while(current){
            Node* nextNode = current -> next;
            if(current -> val <= currentTime){
                count++;
                mpp.erase(current -> str);
                delete(current);
                current = nextNode;
            }
            else{
                break;
            }
        }
        start = current;
        if(start) start -> prev = nullptr;
        if(current == nullptr) last = nullptr;
        return size - count;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */