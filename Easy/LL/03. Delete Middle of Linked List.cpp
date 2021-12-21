
// Que 03). Delete Middle of Linked List 
// Que Link :- https://practice.geeksforgeeks.org/problems/delete-middle-of-linked-list/1

// Implementation

// Fast, Slow & Prev Pointer
// Time Complexity = O(N), Space Complexity = O(1)
Node* deleteMid(Node* head){
    if(!head->next) return NULL;
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;
    while(fast && fast->next){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;        
    return head;
}
