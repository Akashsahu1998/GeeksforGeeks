
// Que 02). Rat in a Maze Problem - I
// Que Link :- https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#

// Implementation

// Using Recursion & Backtracking
// Time Complexity : O(4^(M * N))
// Space Complexity : O(M * N)

class Solution{
    private:
    void solve(vector<vector<int>> &m, int n, string ans, vector<string> &res, int di[], int dj[], vector<vector<bool>> &visited, int i, int j){
        if(i == n-1 && j == n-1){
            res.push_back(ans);
            return;
        }
        
        string direction = "DLRU";
        for(int itr = 0; itr < 4; itr++){
            int nextI = i + di[itr];
            int nextJ = j + dj[itr];
            
            if(nextI >= 0 && nextJ >= 0 && nextI < n && nextJ < n && !visited[nextI][nextJ] && m[nextI][nextJ] == 1){
                
                visited[i][j] = true;
                solve(m, n, ans + direction[itr], res, di, dj, visited, nextI, nextJ);
                visited[i][j] = false;
            }
        }
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> res;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        //           D, L, R,  U
        int di[] = { 1, 0, 0, -1 };
        int dj[] = { 0, -1, 1, 0 };
        
        if(m[0][0] == 1) solve(m, n, "", res, di, dj, visited, 0, 0);
        
        return res;
    }
};
