
// Que 03). The Celebrity Problem
// Que Link :- https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1

// Implementation

// Naive Approach
// Using Vector
// Time Complexity = O(N^2), Space Complexity = O(N)
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& matrix, int n) {
        vector<int> in(n, 0);
        vector<int> out(n, 0);
        
        for(int itr = 0; itr < n; itr++){
            for(int jtr = 0; jtr < n; jtr++){
                if(matrix[itr][jtr] == 1){
                    in[jtr]++;
                    out[itr]++;
                }
            }
        }
        
        for(int itr = 0; itr < n; itr++){
            if(in[itr] == n-1 and out[itr] == 0) return itr;
        }
        return -1;
    }
};
