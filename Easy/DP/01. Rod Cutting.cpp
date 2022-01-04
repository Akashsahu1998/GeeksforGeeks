
// Que 01). Rod Cutting
// Que Link :- https://practice.geeksforgeeks.org/problems/rod-cutting0840/1

// Implementation

// left, right strategy
// https://www.youtube.com/watch?v=eQuJb5gBkkc
// Time Complexity = O(N), Space Complexity = O(N)

class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<int> dp(n);
        
        dp[0] = price[0];
        for(int itr = 1; itr < n; itr++){
            dp[itr] = price[itr];
            
            // assuming 0 based indexing so, left + right = n-1
            int left = 0;
            int right = itr-1;
            
            while(left <= right){
                dp[itr] = max(dp[itr], dp[left] + dp[right]);
                left++;
                right--;
            }
        }
        
        return dp[n-1];
    }
};
