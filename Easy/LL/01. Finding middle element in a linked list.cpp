
// Question) 01. Finding middle element in a linked list 
// Link = https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1

// Implementation

// Efficient Approach
// Time Complexity = O(N), Space Complexity = O(1)
class Solution{
    public:    
    int getMiddle(Node *slow){
        Node* fast = slow;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }
};

