
// Que 02). Detect cycle in a directed graph
// Que Link :- https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1#

// Implementation


// Using DFS
// Time Complexity = O(N+E)
// Space Complexity = (O(2N) + O(N)) => O(N)
// Where N is the nunber of vertices in the graph and E is the number of edges
// https://www.youtube.com/watch?v=uzVUw90ZFIg&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=13

class Solution{
  private:
    bool dfs(int node, vector<int> &vis, vector<int> &dfsVis, vector<int> adj[]){
        vis[node] = 1;
        dfsVis[node] = 1;
        
        for(auto a : adj[node]){
            if(!vis[a]){
                if(dfs(a, vis, dfsVis, adj)) return true;
            }
            else{
                if(dfsVis[a]) return true;
            }
        }
        
        dfsVis[node] = 0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> adj[]) {
        vector<int> vis(v, 0);
        vector<int> dfsVis(v, 0);
        
        for(int i = 0; i < v; i++){
            if(!vis[i]){
                if(dfs(i, vis, dfsVis, adj)) return true;
            }
        }
        
        return false;
    }
};


// 1st Approach
// Using BFS, Kahn's Algo
// Time Complexity = O(N+E)
// Space Complexity = (O(N) + O(N)) => O(N)
// Where N is the nunber of vertices in the graph and E is the number of edges
class Solution{
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> adj[]) {
        vector<int> inDegree(v, 0);
        
        for(int i = 0; i < v; i++){
            for(auto a : adj[i]){
                inDegree[a]++;
            }
        }
        
        queue<int> q;
        for(int i = 0; i < v; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        
        // if there is cycle so, it will not count all nodes
        // if there is no cycle so, it will count all nodes present into graph
        int cnt = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            
            for(auto a : adj[node]){
                inDegree[a]--;
                
                if(inDegree[a] == 0){
                    q.push(a);
                }
            }
        }
        
        return !(cnt == v);
    }
};
