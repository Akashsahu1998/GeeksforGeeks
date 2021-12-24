
// Que) 03. Remove loop in Linked List 
// Que Link :- https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

// Implementation

// Using slow & fast ptr
// Time Complexity = O(N), Space Complexity = O(1)
class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head){
        Node *slow = head, *fast = head, *fastPrev = NULL;
        
        // movign slow as 1 step, fast as 2 step, and mainting fast prev
        while(fast && fast->next){
            slow = slow->next;
            if(!fastPrev) fastPrev = fast->next;
            else fastPrev = fastPrev->next->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        
        // it means loop exist
        if(slow == fast){
            slow = head;
            while(fast != slow){
                slow = slow->next;
                fast = fast->next;  // move fast also as a slow ptr
                fastPrev = fastPrev->next;
            }
            fastPrev->next = NULL;
        }
    }
};
