
// Que 01). Longest Palindrome in a String
// Que Link :- https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1#

// Implementation

// 1st Approach
// Using Dynamic Programming
// Time Complexity = O(N^2)
// Space Complexity = O(N^2)
class Solution{
    public:
    string longestPalin (string s) {
        int n = s.size();
        
         // if string is less than equal to 1, then simply return the string, bcz it will be pallindrome
        if(n <= 1) return s;
        
        // will store the starting index into start and maximum length of the pallindromic substring into len
        int start = 0, len = 0;
        
        // creating DP to store the result of previous substring
        vector<vector<bool>> dp(n, vector<bool>(n));
        
        // using this loop as a gap strategy, gap between itr & jtr index for our string
        for(int gap = 0; gap < n; gap++){
            
            // starting itr from 0, and jtr from gap, so it will maintain the gap between the itr & jtr always
            for(int itr = 0, jtr = gap; jtr < n; jtr++, itr++){
                
                // if gap is 0, it means, its a single char, so its pallindrome, so we can put true into DP
                if(gap == 0){
                    dp[itr][jtr] = true;
                }
                else if(gap == 1){
                    // if gap is 1, it means, there are 2 chars, so if we will check the first char and second char, if both are equal then it means its pallindrome, so we can put true into DP, if not equal then we will put false
                    dp[itr][jtr] = (s[itr] == s[jtr]) ? true : false;
                }
                else{
                    // if gap is more than 1, so we will check the starting char with itr and ending char with jtr in string, if there values are equal and we will also check itr+1 and jtr-1, the result of rest of the string, in DP, if its true, then it means its pallindrome, otherwise not a pallindrome
                    
                    dp[itr][jtr] = (s[itr] == s[jtr] && dp[itr+1][jtr-1]) ? true : false;                    
                }
                
                 // if we are getting big len, then simply update the start and len
                if(dp[itr][jtr] && len < jtr - itr + 1){
                    start = itr;
                    len = jtr - itr + 1;
                }
            }
        }
        
        // return the substr from itr of length (jtr-jtr+1)
        return s.substr(start, len);
    }
};
