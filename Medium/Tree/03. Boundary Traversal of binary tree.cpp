
// Que 03). Boundary Traversal of binary tree 
// Que Link :- https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1#

// Implementation

// Using DFS
// Time Complexity = O(H) + O(H) + O(N) => O(N)
// Space Complexity = O(N)
class Solution {
private:
    bool isLeaf(Node* root){
        return (root->left == NULL && root->right == NULL);
    }

    void addLeftBoundary(Node *root, vector<int> &res){
        Node* cur = root->left;
        
        while(cur){
            if(!isLeaf(cur)) res.push_back(cur->data);
            cur = (cur->left) ? cur->left : cur->right;
        }
    }
    
    void addLeafBoundary(Node *root, vector<int> &res){
        if(isLeaf(root)){
            res.push_back(root->data);
            return;
        }
        
        if(root->left) addLeafBoundary(root->left, res);
        if(root->right) addLeafBoundary(root->right, res);
    }
    
    void addRightBoundary(Node *root, vector<int> &res){
        Node* cur = root->right;
        
        vector<int> temp;
        while(cur){
            if(!isLeaf(cur)) temp.push_back(cur->data);
            cur = (cur->right) ? cur->right : cur->left;
        }
        
        for(int i = temp.size()-1; i >= 0; i--){
            res.push_back(temp[i]);
        }
    }
    
public:
    vector <int> boundary(Node *root){
        vector <int> res;
        
        if(!root) return res;
        
        if(!isLeaf(root)) res.push_back(root->data);
        
        addLeftBoundary(root, res);
        addLeafBoundary(root, res);
        addRightBoundary(root, res);
        
        return res;
    }
};
