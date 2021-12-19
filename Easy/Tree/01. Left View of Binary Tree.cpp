
// Que 01). Left View of Binary Tree 
// Que Link :- https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1#

// Implementation

// Using DFS
// Time Complexity = O(N), Space Complexity = O(H), where H is the height of the binary tree
void findRightSideView(Node* root, vector<int> &res, int level){
    if(!root) return;
    if(level > res.size()) res.push_back(root->data);
    findRightSideView(root->left, res, level+1);
    findRightSideView(root->right, res, level+1);
}

vector<int> leftView(Node *root){
   vector<int> res;
    findRightSideView(root, res, 1);
    return res;
}


// Using BFS
// Time Complexity = O(N), Space Complexity = O(N)
vector<int> leftView(Node *root){
   vector<int> res;
    if(!root) return res;
    
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        int size = q.size();
        res.push_back(q.front()->data);
        
        for(int itr = 0; itr < size; itr++){
            Node* temp = q.front();
            q.pop();
            
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
    return res;
}
