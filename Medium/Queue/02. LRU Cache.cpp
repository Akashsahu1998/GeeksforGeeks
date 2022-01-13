
// Que 02). LRU Cache
// Que Link :- https://practice.geeksforgeeks.org/problems/lru-cache/1

// Implementation

// Using doubly linked list & unordered_map
// Time Complexity = O(1), Space Complexity = O(N)
class LRUCache
{
    public:
    int size;    
    
    class Node{
    public:
        int key, val;
        Node *prev, *next;

        Node(int k, int v){
            key = k;
            val = v;            
        }
    };
    
    // head->next will hold the recently added node
    Node *head = new Node(-1, -1);
    
    // tail->prev will hold the old added node
    Node *tail = new Node(-1, -1);
    unordered_map<int, Node*> mp;    
    
    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap){
        size = cap;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(Node *newNode){
        Node* temp = head->next;        
        head->next = newNode;
        newNode->prev = head;
        newNode->next = temp;
        temp->prev = newNode;
    }
    
    void deleteNode(Node *delNode){
        Node *delNodePrev = delNode->prev;
        Node *delNodeNext = delNode->next;
        delNodePrev->next = delNodeNext;
        delNodeNext->prev = delNodePrev;        
    }
    
    //Function to return value corresponding to the key.
    int get(int key){
        if(mp.find(key) != mp.end()){
            // holding the existing result node
            Node *resNode = mp[key];
            int res = resNode->val;
            
            // delete from map
            mp.erase(key);
            
            // delete the node
            deleteNode(resNode);
            
            // add the node, so it will be recently added node
            addNode(new Node(key, res));
            
            // add the key again into map with new address
            mp[key] = head->next;  
                
            return res;
        }
        return -1;
    }
    
    //Function for storing key-value pair.
    void set(int key, int value){
        if(mp.find(key) != mp.end()){
            // holding the existing node
            Node *temp = mp[key];
            
            // delete from map
            mp.erase(key);
            
            // delete the node
            deleteNode(temp);
        }
        if(mp.size() == size){
            // holding the existing node
            Node *temp = tail->prev;
            
            // delete from map            
            mp.erase(temp->key);
            
            // delete the node
            deleteNode(temp);
        }
        
        // add the node, so it will be recently added node
        addNode(new Node(key, value));
        
        // add the key again into map with new address
        mp[key] = head->next;
    }
};
