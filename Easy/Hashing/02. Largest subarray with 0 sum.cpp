
// Que 02). Largest subarray with 0 sum
// Que Link :- https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

// Implementation

// Using unoredered_map
// Time Complexity = O(N), Space Complexity = O(N)
class Solution{
    public:
    int maxLen(vector<int>&arr, int n){   
        int maxLength = 0, sum = 0;
        unordered_map<int, int> mp;
        
        for(int itr = 0; itr < n; itr++){
            
            // calculating the sum on each index
            // then this problem will become Largest subarray with 0 sum
            sum += arr[itr];
            
            // To handle sum = 0 at last index, i.e = -5 -5 5 5
            if(sum == 0){
                maxLength = itr+1;
            }
            
            // if sum is already in the map, then just calculate the maximum length of the subarray
            // if sum is not present then just add it into the map
            if(mp.find(sum) != mp.end()){
                maxLength = max(maxLength, itr - mp[sum]);
            }
            else mp[sum] = itr;
        }
        
        return maxLength;
    }
};
