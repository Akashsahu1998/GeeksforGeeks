
// Que) 11. Detect Loop in linked list
// Que Link :- https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1

// Implementation

// using two pointer
// Single Traversal
// Time Complexity = O(N), Space Complexity = O(1)
class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head){
        Node *slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }
};

