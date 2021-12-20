
// Que 02). Count pairs with given sum 
// Que Link :- https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1#

// Implementation

// Using Unordered Map
// Time Complexity = O(N), Space Complexity = O(N)
class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        int count = 0;
        unordered_map<int, int> mp;
        
        for(int itr = 0; itr < n; itr++){
            int tempSum = k - arr[itr];
            if(mp[tempSum]) count += mp[tempSum];
            mp[arr[itr]]++;
        }
        return count;
    }
};
