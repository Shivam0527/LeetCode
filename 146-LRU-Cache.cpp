class LRUCache {
public:
    class Node{
        public:

        Node* next;
        Node* prev;
        int key, val;

        Node(int k, int v) {
            key = k;
            val = v;
            next = nullptr;
            prev = nullptr;
        }
    };

    Node* dummyHead;
    Node* dummyTail;

    unordered_map<int, Node*> mpp;
    int cap;

    void insertAfterHead(Node* addNode) {
        addNode->next = dummyHead->next;
        addNode->prev = dummyHead;

        dummyHead->next->prev = addNode;
        dummyHead->next = addNode;
    }

    void deleteNode(Node* dltNode) {
        dltNode->prev->next = dltNode->next;
        dltNode->next->prev = dltNode->prev;


        dltNode->next = NULL;
        dltNode->prev = NULL;
    }

    LRUCache(int capacity) {
        cap = capacity;

        dummyHead = new Node(-1, -1);
        dummyTail = new Node(-1, -1);

        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
    }
    
    int get(int key) {
        if(mpp.find(key) == mpp.end()) {
            return -1;
        } 

        Node* node = mpp[key];

        deleteNode(node);

        insertAfterHead(node);

        return node->val;        
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()) {
            Node* existingNode = mpp[key];

            deleteNode(existingNode);

            existingNode->val = value;

            insertAfterHead(existingNode);
        }
        else {
            if(mpp.size() == cap) {
                Node* lruNode = dummyTail->prev;

                deleteNode(lruNode);
                mpp.erase(lruNode->key);

                delete lruNode;
            }

            Node* newNode = new Node(key, value);
            mpp[key] = newNode;

            insertAfterHead(newNode);
        }
    }
};

const int ZERO = []()
{
\tstd::ios_base::sync_with_stdio(false);
\tstd::cin.tie(nullptr);
\treturn 0;
}();


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */