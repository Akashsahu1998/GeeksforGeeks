
// Que 03). Two Sum
// Que Link :- https://practice.geeksforgeeks.org/problems/key-pair5616/1

// Implementation

// Using unoredered_map
// Time Complexity = O(N), Space Complexity = O(N)
class Solution
{
    public:
    bool keypair(vector<int> arr, int n, int x){
        unordered_map<int, int> mp;
        
        for(int itr = 0; itr < n; itr++){
            if(mp[x - arr[itr]]) return true;
            else mp[arr[itr]]++;
        }
        
        return false;
    }
};
