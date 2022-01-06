
// Que 01). Matrix Chain Multiplication
// Que Link :- https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1#

// Implementation

// DP
// Using Tabulation, gap and cut strategy
// Time Complexity = O(N^3), Space Complexity = O(N^2)
class Solution{
public:
    int matrixMultiplication(int n, int arr[]){
        
        // create a matrix of length-1
        vector<vector<int>> dp(n-1, vector<int>(n-1, 0));
        
        for(int gap = 0; gap < n-1; gap++){
            for(int itr = 0, jtr = gap; jtr < n-1; itr++, jtr++){
                if(gap == 0){
                    dp[itr][jtr] = 0;
                }
                else if(gap == 1){
                    dp[itr][jtr] = arr[itr] * arr[jtr] * arr[jtr+1];
                }
                else{
                    int minValue = INT_MAX;
                    
                    for(int ktr = itr; ktr < jtr; ktr++){
                        // dp : itr to ktr left half, ktr+1 to jtr right half
                        // arr : itr * ktr+1 left half, ktr+1 * jtr+1 right half
                        
                        int left = dp[itr][ktr];
                        int right = dp[ktr+1][jtr];
                        int leftMultiplyRight = arr[itr] * arr[ktr+1] * arr[jtr+1];
                        int total = left + right + leftMultiplyRight;
                        
                        minValue = min(minValue, total);
                    }
                    
                    dp[itr][jtr] = minValue;
                }
            }
        }
        
        // returning the last index of first row
        return dp[0][n-2];
    }
};
