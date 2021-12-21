
// Que 05). Reverse a linked list 
// Que Link :- https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1

// Implementation

// Time Complexity = O(N), Space Complexity = O(1)
struct Node* reverseList(struct Node *head){
    if(!head) return NULL;
    struct Node* prev = NULL;
    while(head->next){
        struct Node* temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    head->next = prev;
    return head;
}

