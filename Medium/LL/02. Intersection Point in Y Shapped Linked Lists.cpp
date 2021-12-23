
// Que) 02. Intersection Point in Y Shapped Linked Lists 
// Que Link :- https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1

// Implementation

// Naive Approach
// Using Unordered Map
// Time Complexity = O(N), Space Complexity = O(N)
int intersectPoint(Node* head1, Node* head2){    
    unordered_map<Node*, int> mp;
        
        // Storing the Node as a key value pair
    Node* cur = head1;        
    while(cur){
        mp[cur]++;
        cur = cur->next;
    }
    
    // Iteratign & Checking if node is already present into map,
    // it means that is the intersection point.
    cur = head2;        
    while(cur){
        if(mp[cur]) return cur->data;
        cur = cur->next;
    }
    
    // if not present
    return -1;
}
