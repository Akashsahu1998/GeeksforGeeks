
// Que) 13. Delete without head pointer
// Que Link :- https://www.geeksforgeeks.org/delete-a-node-from-linked-list-without-head-pointer/

// Implementation

// Time Complexity = O(1), Space Complexity = O(1)
class Solution
{
    public:
    //Function to delete a node without any reference to head pointer.
    void deleteNode(Node *del){
       Node* temp = del->next;
        del->data = temp->data;
        del->next = temp->next;
        delete temp;
    }
};


