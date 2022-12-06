
// Que 02). Largest subarray with 0 sum
// Que Link :- https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

// Implementation

// using unoredered_map & preSum
// Time Complexity = O(N), Space Complexity = O(N)
class Solution{
    public:
    int maxLen(vector<int>&arr, int n){
        unordered_map<int, int> mp;
        int maxLength = 0, preSum = 0;
        for(int i = 0; i < arr.size(); i++){
            
            // calculating the preSum on each index
            // then this problem will become Largest subarray with 0 sum
            preSum += arr[i];
            
            // if preSum is already in the map, then just calculate the maximum length of the subarray
            if(mp.find(preSum) != mp.end()){
                maxLength = max(maxLength, i - mp[preSum]);
            }
            
            // To handle preSum = 0,
            // i.e = {-5 -5 5 5}
            // i.e = {1, -2, 1, 2}
            else if(preSum == 0){
                maxLength = max(maxLength, i+1);
            }
            
            // if preSum is not present then just add it into the map
            else{
                mp[preSum] = i;
            }
        }
        
        return maxLength;
    }
};
