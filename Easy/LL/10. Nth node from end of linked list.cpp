
// Que) 9. Nth node from end of linked list
// Que Link :- https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1

// Implementation

// using two pointer
// Single Traversal
// Time Complexity = O(N), Space Complexity = O(1)
int getNthFromLast(Node *head, int n){
       Node *ptr1 = head, *ptr2 = head;
    
        while(ptr1){
            // movign the ptr1 n steps ahead of ptr2,
            // so when ptr1 reaches null it means ptr2 will be
            // standing on a nth node from last
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

