class LFUCache {
public:
    class Node{
        public:

        int key, val, cnt;
        Node* next;
        Node* prev;

        Node(int k, int v, int c) {
            key = k;
            val = v;
            cnt = c;
        }
    };

    Node* head;
    Node* tail;

    int cap;
    unordered_map<int, Node*> mpp;

    void insertNode(Node* addNode) {
        Node* temp = head;

        while(temp->next->cnt > addNode->cnt) {
            temp = temp->next;
        }

        addNode->next = temp->next;
        addNode->prev = temp;

        addNode->next->prev = addNode;
        temp->next = addNode;
    }

    void deleteNode(Node* dltNode) {
        dltNode->prev->next = dltNode->next;
        dltNode->next->prev = dltNode->prev;

        dltNode->next = NULL;
        dltNode->prev = NULL;
    }

    LFUCache(int capacity) {
        cap = capacity;

        head = new Node(-1, -1, -1);
        tail = new Node(-1, -1, -1);

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mpp.find(key) == mpp.end()) {
            return -1;
        }

        Node* node = mpp[key];

        node->cnt += 1;

        deleteNode(node);
        insertNode(node);  

        return node->val;   
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()) {
            Node* existingNode = mpp[key];

            existingNode->cnt +=1;
            existingNode->val = value;

            deleteNode(existingNode);

            insertNode(existingNode);
        } 
        else {
            if(mpp.size() == cap) {
                Node* temp = tail->prev;

                deleteNode(temp);
                mpp.erase(temp->key);

                delete temp;
            }

            Node* newNode = new Node(key, value, 1);

            mpp[key] = newNode;

            insertNode(newNode);
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
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */