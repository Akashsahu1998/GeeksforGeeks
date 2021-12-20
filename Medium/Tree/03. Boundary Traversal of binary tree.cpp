
// Que 03). Boundary Traversal of binary tree 
// Que Link :- https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1#

// Implementation

// Using DFS
// Time Complexity = O(N), Space Complexity = O(N)
class Solution {
public:
    void findLeft(Node* root, vector<int> &res){
        if(!root) return;
        if(root->left) {
            res.push_back(root->data);
            findLeft(root->left, res);
        }
        else if(root->right) {
            res.push_back(root->data);
            findLeft(root->right, res);
        }
    }
    
    void findLeaf(Node* root, vector<int> &res){
        if(!root) return;
        findLeaf(root->left, res);
        if(root->left == NULL && root->right == NULL) res.push_back(root->data);
        findLeaf(root->right, res);
    }
    
    void findRight(Node* root, vector<int> &res){
        if(!root) return;
        if(root->right) {
            findRight(root->right, res);
            res.push_back(root->data);
        }
        else if(root->left) {
            findRight(root->left, res);
            res.push_back(root->data);
        }
    }
    
    vector <int> boundary(Node *root){
        vector<int> res;
        res.push_back(root->data);
        findLeft(root->left, res);
        findLeaf(root, res);
        findRight(root->right, res);
        return res;
    }
};
