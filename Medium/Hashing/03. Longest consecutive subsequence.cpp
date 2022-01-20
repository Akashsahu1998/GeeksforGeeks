
// Que 03). Longest consecutive subsequence
// Que Link :- https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1

// Implementation

// Using Unordered Map
// Time Complexity = O(N), Space Complexity = O(N)
class Solution{
    public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n){
        
        // taking map to store the frequency of a ele, so in this way we can check, that element is present or not.
        unordered_map<int, int> mp;
        
        // storing the frequency
        for(int itr = 0; itr < n; itr++){
            mp[arr[itr]]++;
        }
        
        int maxLen = INT_MIN;
        
        // iterating over the arr, and
        // checking if any arr[itr]-1 is present into map, then do nothing, 
        // if not present it means, its our starting of the sub sequence so, we will count how many values of this sequence is present while moving it by 1
        for(int itr = 0; itr < n; itr++){
            int len = 0;
            int val = arr[itr];
            if(mp[val-1]){
                continue;
            }
            else{
                while(mp[val]){
                    len++;
                    val++;
                }
                
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};
