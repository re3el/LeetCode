class LRUCache {
    
    struct DLinkedNode 
    {        
        int key;
        int val;
        
        DLinkedNode* pre;
        DLinkedNode* post;
        DLinkedNode(){}
        DLinkedNode(int k, int v): key(k), val(v), pre(NULL), post(NULL){}
    }*head,*tail;
    
    unordered_map<int,DLinkedNode*>hashT;
    int cap,cnt;
    
    // always add to the next of head
    void addNode(DLinkedNode *node)
    {
        node->post = head->post;
        node->pre = head;
        
        head->post->pre = node;
        head->post = node;
    }
    
    void pushToTop(DLinkedNode *node)
    {
        deleteNode(node);
        addNode(node);
    }    
    
    void deleteNode(DLinkedNode* node)
    {
        node->pre->post = node->post;
        node->post->pre = node->pre;        
    }
    
    DLinkedNode* deleteTail()
    {
        DLinkedNode *node = tail->pre;
        deleteNode(node);
        return node;
    }    
    
public:
    LRUCache(int capacity) 
    {        
        cnt = 0;
        cap = capacity;
        
        head = new DLinkedNode();        
        head->post = tail;
        head->pre = NULL;
        
        tail = new DLinkedNode();
        tail->post = NULL;
        tail->pre = head;        
    }
    
    int get(int key) 
    {        
        DLinkedNode *node = hashT[key];
        if(node != NULL)    
        {            
            pushToTop(node);
            return node->val;
        }
        else
            return -1;        
    }
    
    void put(int key, int value) 
    {
        DLinkedNode *node = hashT[key];
        if(node != NULL)
        {            
            node->val = value;
            pushToTop(node);
        }
        else
        {
            ++cnt;            
            DLinkedNode *node = new DLinkedNode(key,value);
            addNode(node);
            hashT[key] = node;
            
            if(cnt > cap)
            {                
                DLinkedNode *node = deleteTail();
                hashT[node->key] = NULL;
                --cnt;                
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */