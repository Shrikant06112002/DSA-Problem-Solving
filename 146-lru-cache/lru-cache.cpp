// struct Node{
//     int key,value;
//     Node *prev,*next;
//     Node(int key,int value){
//         this->key=key;
//         this->value=value;
//         prev=nullptr;
//         next= nullptr;
//     }
// };
class LRUCache {
public:
    struct Node{
        int key,value;
        Node *prev,*next;
        Node(int key,int value){
            this->key=key;
            this->value=value;
            prev=nullptr;
            next= nullptr;
        }
    };
    int cap;
    Node* head = new Node(0,0);
    Node* tail = new Node(0,0);
    unordered_map<int,Node*> um;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }

    void insert(Node* newNode){
        Node *temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(Node* delNode){
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;
        delPrev->next=delNext;
        delNext->prev=delPrev;
        // delete delNode;
    }

    int get(int key) {
        if(um.find(key)!=um.end()){
            Node* exitNode = um[key];
            int res = exitNode->value;
            um.erase(key);
            deleteNode(exitNode);
            insert(exitNode);
            um[key] = head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(um.find(key)!=um.end()){
            Node* exitNode = um[key];
            um.erase(key);
            deleteNode(exitNode);
        }
        if(um.size()==cap){
            int rLru = tail->prev->key;
            um.erase(rLru);
            deleteNode(tail->prev);
        }
        Node* newNode = new Node(key,value);
        um[key]=newNode;
        insert(newNode);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */