
// Que 01). DFS of Graph
// Que Link :- https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1/#

// Implementation

// Using DFS
//https://www.youtube.com/watch?v=uDWljP2PGmU&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=7
// Time Complexity = O(V+E), Where V is the vertices and E is the edges of the graph
// Space Complexity = O(V)

class Solution{
  private:
    void dfs(vector<int> adj[], vector<int> &dfsResult, vector<int> &visited, int node) {
        dfsResult.push_back(node);
        visited[node] = 1;
        for(auto a : adj[node]){
            if(!visited[a]){
                dfs(adj, dfsResult, visited, a);
            }
        }
    }
    
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int v, vector<int> adj[]) {
        vector<int> dfsResult;
        vector<int> visited(v+1);
        
        // bcz this is a connected graph
        // for(int i = 1; i < visited.size(); i++){
            // if(!visited[i]){
                dfs(adj, dfsResult, visited, 0);
            // }
        // }
        
        return dfsResult;
    }
};
