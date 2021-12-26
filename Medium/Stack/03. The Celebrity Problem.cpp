
// Que 03). The Celebrity Problem
// Que Link :- https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1

// Implementation

// 1st Approach
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


// 2nd Approach
// reference : https://www.youtube.com/watch?v=CiiXBvrX-5A
// Efficient Approach
// Using Stack
// Time Complexity = O(N), Space Complexity = O(N)
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& matrix, int n) {
        stack<int> st;
        for(int itr = 0; itr < n; itr++){
            st.push(itr);
        }
        
        while(st.size() > 1){
            int itr = st.top();
            st.pop();
            int jtr = st.top();
            st.pop();
            if(matrix[itr][jtr]){
                // itr knows jtr
                st.push(jtr);
            }
            else{
                // jtr knows itr
                st.push(itr);
            }
        }
        
        int lastValue = st.top();
        st.pop();
        for(int itr = 0; itr < n; itr++){
            if(itr != lastValue && (matrix[itr][lastValue] == 0 || matrix[lastValue][itr] == 1)){
                 return -1;
            }
        }
        return lastValue;
    }
};


// 3rd Approach
// reference : https://www.youtube.com/watch?v=Z5AEc12ieOs
// Most Efficient Approach
// Time Complexity = O(N), Space Complexity = O(1)
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& matrix, int n) {
        int celebrity = 0;
        for(int itr = 1; itr < n; itr++){
            if(matrix[celebrity][itr]){
                celebrity = itr;
            }
        }
        
        for(int itr = 0; itr < n; itr++){
            if(itr != celebrity && (matrix[celebrity][itr] == 1 || matrix[itr][celebrity] == 0)){
                return -1;
            }
        }
        return celebrity;
    }
};
