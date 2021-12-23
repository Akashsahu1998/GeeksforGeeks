
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


// Efficient Approach
// Idea is to iterate over a list two times
// Time Complexity = O(N), Space Complexity = O(1)
int intersectPoint(Node* head1, Node* head2){
    Node* curA = head1;
    Node* curB = head2;
    
    // For example
    // headA = [1, 2, 3, 4]
    // headB = [8, 4]
    // Just assume it as headA = headA + headB, and headB = headB + headA
    // headA = [1, 2, 3, 4, 8, 4]
    // headB = [8, 4, 1, 2, 3, 4]
    // we are iterating in this way
    
    while(curA != curB){
        curA = curA ? curA->next : head2;
        curB = curB ? curB->next : head1;
    }
    return (curA) ? curA->data : -1;
}
