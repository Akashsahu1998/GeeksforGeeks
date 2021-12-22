
// Que 05). Reverse a linked list 
// Que Link :- https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1

// Implementation

// Time Complexity = O(N), Space Complexity = O(1)
class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k){
        if(!head->next || k == 0) return head;
        Node* cur = head;
        Node* prev = NULL;
        
        while(cur && k--){
            prev = cur;
            cur = cur->next;
        }
        
        if(!cur) return head;
        
        Node* returnValue = cur;
        prev->next = NULL;
        
        while(cur->next){
            cur = cur->next;
        }
        
        cur->next = head;
        return returnValue;
    }
};
