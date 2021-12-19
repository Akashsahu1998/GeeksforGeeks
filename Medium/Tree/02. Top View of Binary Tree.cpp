
// Que 02). Top View of Binary Tree
// Que Link :- https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1#

// Implementation

// Using queue and map
// Time Complexity = O(NLogN), Space Complexity = O(N)
class Solution
{
    public:
    vector<int> topView(Node *root){
        queue<pair<Node*, int>> q;
        map<int, int> mp;
        q.push({root, 0});
        
        while(!q.empty()){
            for(int itr = 0; itr < q.size(); itr++){
                Node* temp = q.front().first;
                int val = q.front().second;
                q.pop();
                
                if(!mp[val]) mp[val] = temp->data;
                
                if(temp->left) q.push({temp->left, val-1});
                if(temp->right) q.push({temp->right, val+1});
            }
        }
        
        vector<int> res;
        for(auto a : mp){
            res.push_back(a.second);
        }
        
        return res;
    }
};
