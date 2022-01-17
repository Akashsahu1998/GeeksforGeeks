
// Que 03). Count distinct elements in every window
// Que Link :- https://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1

// Implementation

// Using unoredered_map
// Time Complexity = O(N), Space Complexity = O(K)
class Solution{
  public:
    vector <int> countDistinct (int arr[], int n, int k){
        unordered_map<int, int> mp;
        vector<int> res;
        
        for(int itr = 0; itr < k; itr++){
            mp[arr[itr]]++;
        }
        res.push_back(mp.size());
        
        for(int itr = k, jtr = 1; itr < n; itr++, jtr++){
            mp[arr[jtr-1]]--;
            if(!mp[arr[jtr-1]]) mp.erase(arr[jtr-1]);
            mp[arr[itr]]++;
            
            res.push_back(mp.size());
        }
        
        return res;
    }
};

