
// Que) 04. Merge two sorted linked lists
// Que Link :- https://practice.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1

// Implementation

// simnply traversing and adding nodes into new list based on the comparison
// Time Complexity = O(N), Space Complexity = O(1)

// adding a new node to dummy list
Node* addNode(Node *dummy, int data){
    Node* newNode = new Node(data);
    dummy->next = newNode;
    return dummy->next;
}

//Function to merge two sorted linked list.
Node* sortedMerge(Node* head1, Node* head2){  
    Node *dummy = new Node(0);
    Node *res = dummy;
    
    // moving both head1 & head2 untill any one reaches null and
    // comparing values, bcased on that adding into dummy list
    while(head1 && head2){
        if(head1->data <= head2->data){
            dummy = addNode(dummy, head1->data);
            head1 = head1->next;
        }
        else{
            dummy = addNode(dummy, head2->data);
            head2 = head2->next;
        }
    }
    
    // if head1 is not empty then simply assigning head1, otherwise head2
    head1 = head1 ? head1 : head2;
    
    // checking if any of the list are non empty then adding that list into dummy list
    while(head1){
        dummy = addNode(dummy, head1->data);
        head1 = head1->next;
    }
    
    // returning next, bcz res is pointing to 0
    return res->next;
}
