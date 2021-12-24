
// Que) 9. Nth node from end of linked list
// Que Link :- https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1

// Implementation

// using two pointer
// Single Traversal
// Time Complexity = O(N), Space Complexity = O(1)
int getNthFromLast(struct Node *head, int n){
    struct Node *ptr1 = head, *ptr2 = head;
    
    while(ptr1){
        if(n > 0){
            ptr1 = ptr1->next;
            n--;
        }
        else{
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }
    return (n) ? -1 : ptr2->data;
}

