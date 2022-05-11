
// Que 02). Number of Coins
// Que Link :- https://practice.geeksforgeeks.org/problems/number-of-coins1824/1/#

// Implementation

// Iterative solution using DP
// Time Complexity = O(amount*coins.size())
// Space Complexity = O(amount)
class Solution{
    public:
	int minCoins(int coins[], int m, int v) { 
	    vector<int> dp(v+1, v+1);
        dp[0] = 0;
        for(int itr = 1; itr < dp.size(); itr++){
            for(int jtr = 0; jtr < m; jtr++){
                if(coins[jtr] > itr) continue;
                dp[itr] = min(dp[itr - coins[jtr]]+1, dp[itr]);
            }
        }        
        return (dp[v] == v+1) ? -1 : dp[v];
	} 	  
};
