
// Que 01). Binary Tree to DLL
// Que Link :- https://www.geeksforgeeks.org/in-place-convert-a-given-binary-tree-to-doubly-linked-list

// Implementation
// Time Complexity = O(N), Space Complexity = O(H) where H is the height of the binary tree

class Solution
{
    public: 
    void convertBinaryTreeToDoublyLinkedList(Node* root, Node* &head, Node* &prev, int &flag){
        if(!root) return;
        convertBinaryTreeToDoublyLinkedList(root->left, head, prev, flag);
        if(flag == 0){
            flag = 1;
            head = root;
            prev = root;
        }
        else{
            prev->right = root;
            prev->right->left = prev;
            prev = root;
        }
        convertBinaryTreeToDoublyLinkedList(root->right, head, prev, flag);
    }
    
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        Node *head = NULL, *prev = NULL;
        int flag = 0;
        convertBinaryTreeToDoublyLinkedList(root, head, prev, flag);
        return head;
    }
};
