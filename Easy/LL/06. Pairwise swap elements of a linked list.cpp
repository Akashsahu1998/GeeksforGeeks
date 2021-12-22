
// Que 06). Pairwise swap elements of a linked list
// Que Link :- https://practice.geeksforgeeks.org/problems/pairwise-swap-elements-of-a-linked-list-by-swapping-data/1

// Implementation

// Time Complexity = O(N), Space Complexity = O(1)
class Solution
{
    public:
    Node* pairWiseSwap(struct Node* head) {
        if(!head || !head->next) return head;
        
        struct Node *prev1 = NULL, *prev2 = NULL;
        struct Node *cur = head;
        struct Node *nextt = cur->next;
        
        while(nextt){
            if(!prev1) head = nextt;
            prev2 = prev1;
            prev1 = cur;
            cur->next = nextt->next;
            nextt->next = prev1;
            if(prev2) prev2->next = nextt;
            cur = cur->next;
            if(!cur) break;
            nextt = cur->next;
        }
        return head;
    }
};

