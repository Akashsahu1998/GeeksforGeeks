
// Que 01). Largest subarray of 0's and 1's
// Que Link :- https://practice.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s/1

// Implementation

// Using unoredered_map
// Time Complexity = O(N), Space Complexity = O(N)
class Solution{
  public:
    int maxLen(int arr[], int n){
        int maxLength = 0, sum = 0;
        unordered_map<int, int> mp;
        
        // replacing 0 by -1
        // then this problem will become Largest subarray with 0 sum
        for(int itr = 0; itr < n; itr++){
            arr[itr] = (arr[itr] == 0) ? -1 : 1;
        }
        
        for(int itr = 0; itr < n; itr++){
        	
        	// calculating the sum on each index
            sum += arr[itr];
            
            // To handle sum = 0 at last index, i.e = 0 0 1 1
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
