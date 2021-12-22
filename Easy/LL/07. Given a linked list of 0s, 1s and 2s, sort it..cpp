
// Que) 7. Given a linked list of 0s, 1s and 2s, sort it. 
// Que Link :- https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

// Implementation

// Time Complexity = O(N), Space Complexity = O(1)
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        Node *cur = head;
        Node *ptrZero = NULL, *ptrZeroHead = NULL;
        Node *ptrOne = NULL, *ptrOneHead = NULL;
        Node *ptrTwo = NULL, *ptrTwoHead = NULL;
        
        while(cur){
            if(cur->data == 0){
                if(!ptrZero){
                    ptrZero = cur;
                    ptrZeroHead = ptrZero;
                }
                else {
                    ptrZero->next = cur;
                    ptrZero = ptrZero->next;
                }
            }
            else if(cur->data == 1){
                if(!ptrOne){
                    ptrOne = cur;
                    ptrOneHead = ptrOne;
                }
                else {
                    ptrOne->next = cur;
                    ptrOne = ptrOne->next;
                }
            }
            else if(cur->data == 2){
                if(!ptrTwo){
                    ptrTwo = cur;
                    ptrTwoHead = ptrTwo;
                }
                else {
                    ptrTwo->next = cur;
                    ptrTwo = ptrTwo->next;
                }
            }
            cur = cur->next;
        }
        
        Node *returnNode = NULL;
        if(ptrZero){
            returnNode = ptrZeroHead;
        }
        
        if(ptrOne){
            if(!returnNode) returnNode = ptrOneHead;
            if(ptrZero) ptrZero->next = ptrOneHead;
        }
        
        if(ptrTwo){
            if(!returnNode) returnNode = ptrTwoHead;
            if(ptrZero && ptrOne){
                ptrOne->next = ptrTwoHead;
            }
            else if(!ptrZero && ptrOne){
                ptrOne->next = ptrTwoHead;
            }
            else if(ptrZero){
                ptrZero->next = ptrTwoHead;
            }
        }
        
        if(ptrTwo){
            ptrTwo->next = NULL;
        }
        else if(ptrOne){
            ptrOne->next = NULL;
        }
        
        return returnNode;
    }
};

