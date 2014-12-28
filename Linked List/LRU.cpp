class LRUCacheNode {
public: 
    LRUCacheNode(){
        left = NULL;
        right = NULL;    
    };
    
    LRUCacheNode(int key, int value){
        left = NULL;
        right = NULL;    
        m_key = key;
        m_value = value;
    };
    
    int getKey() {
        return m_key;
    }
    
    void setKey(int key) {
        m_key = key;
    }
    
    int getValue() {
        return m_value;
    }
    
    void setValue(int value) {
        m_value = value;
    }
    
    LRUCacheNode *left;
    LRUCacheNode *right; 
    
private:
    int m_key;
    int m_value;
};


class LRUCache{
public:
    LRUCache(int capacity) {
        if (capacity <=0)
            return ;
        m_capacity = capacity;
        m_cur_capacity = 0;
        m_head = new LRUCacheNode(INT_MIN,INT_MIN);
        m_head->left = NULL;
        m_head->right = NULL;
        m_tail = new LRUCacheNode(INT_MAX,INT_MAX);
        m_tail->left = NULL;
        m_tail->right = NULL;
    }
    
    int get(int key) {
        if (m_dict.find(key) != m_dict.end() ) {
            LRUCacheNode *m_check = m_dict[key];
            moveNodeToHead(m_check);
            return m_check->getValue();
        }
        else {
            return -1;
        }
    }
    
    void set(int key, int value) { 
        if (m_cur_capacity == 0) {
            LRUCacheNode *newhead = new LRUCacheNode(key, value);
            m_dict[key] = newhead;
            m_cur_capacity ++; 
            newhead->left = m_head;
			newhead->right = m_tail;
            m_head->right = newhead;
            m_tail->left = newhead;
            return;
        }
        // if the key is existed in the list, we update the node
        // and move it to the head of list
        if (m_dict.find(key) != m_dict.end()) {
            m_dict[key]->setValue(value);
            moveNodeToHead(m_dict[key]);
            return;
        }
        // Insert a new node to the list and update the dict
        // 1. space is enought 2. space is not
        if (m_cur_capacity < m_capacity) {
            LRUCacheNode *newnode = new LRUCacheNode(key, value);
            m_dict[key] = newnode;
            m_cur_capacity ++;
            addNodeToHead(newnode);
            return;
        }
        // actually it can only be equal to the capacity
        else { 
            // delete first
            deleteNodeAtTail();
            LRUCacheNode *newnode = new LRUCacheNode(key, value);
            m_dict[key] = newnode;
            m_cur_capacity ++;
            addNodeToHead(newnode);
            return;
        } 
    }
    
    // m_head is always existed
    void moveNodeToHead(LRUCacheNode *currNode) {  
        if (currNode == m_head->right)
            return;
        // disconect first
        currNode->left->right = currNode->right;
        currNode->right->left = currNode->left;
        // same as add new node to head
        addNodeToHead(currNode);
        return;
    } 
    
    void addNodeToHead(LRUCacheNode *currNode) {
        m_head->right->left = currNode;
        currNode->right = m_head->right;
        m_head->right = currNode;
        currNode->left = m_head;
        return;
    }
    
    void deleteNodeAtTail() {
        LRUCacheNode * m_last = m_tail->left;
        m_last->left->right = m_tail;
        m_tail->left = m_last->left;
        m_dict.erase(m_last->getKey());
        delete m_last;
        return;
    }

private:
    // use for storing recently used node
    LRUCacheNode *m_head;
    LRUCacheNode *m_tail;
    int m_capacity;
    unordered_map<int, LRUCacheNode*> m_dict;
    int m_cur_capacity;
};

