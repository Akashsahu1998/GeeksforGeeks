
// Que 04). Min distance between two given nodes of a Binary Tree
// Que Link :- https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1/#

// Implementation

// Approach Using DFS
// Time Complexity = O(N), Space Complexity = O(H) where H is the height of the Binary Tree
// In this solution we require three traversal of binary tree.

class Solution{
    public:
    
    Node* findLCA(Node* root, int a, int b){
        if(!root) return NULL;
        if(root->data == a or root->data == b) return root;
        
        Node* leftLCA = findLCA(root->left, a, b);
        Node* rightLCA = findLCA(root->right, a, b);
        
        if(leftLCA && rightLCA) return root;
        return leftLCA ? leftLCA : rightLCA;
    }
    
    int findLevelFromLCAToNumber(Node* root, int k, int level){
        if (root == NULL)
            return -1;
        if (root->data == k)
            return level;
     
        int left = findLevelFromLCAToNumber(root->left, k, level + 1);
        if (left == -1)
            return findLevelFromLCAToNumber(root->right, k, level + 1);
        return left;
    }
    
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findDist(Node* root, int a, int b) {
        Node* lca = findLCA(root, a, b);
        int dist1 = findLevelFromLCAToNumber(lca, a, 0);
        int dist2 = findLevelFromLCAToNumber(lca, b, 0);
        return dist1 + dist2;
    }
};
