
// Que 01). Bottom View of Binary Tree 
// Que Link :- https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1#

// Implementation

// Using queue and map
// Time Complexity = O(NLogN), Space Complexity = O(N)
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        if(!root) return ans;
        
        queue<pair<Node*, int>> q;
        map<int, int> mp;
        q.push({root, 0});
        
        while(!q.empty()){
            Node *temp = q.front().first;
            int val = q.front().second;
            q.pop();
            
            if(temp->left){
                q.push({temp->left, val-1});
            }
            if(temp->right){
                q.push({temp->right, val+1});
            }
            
            mp[val] = temp->data;
        }
        
        for(auto m: mp){
            ans.emplace_back(m.second);
        }
        
        return ans;
    }
};
