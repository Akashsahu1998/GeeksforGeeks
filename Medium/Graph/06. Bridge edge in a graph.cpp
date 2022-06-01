
// Que 06). Bridge edge in a graph 
// Que Link :- https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1#

// Implementation

// 1st Approach
// Using DFS
// Time Complexity = O(N+E)
// Space Complexity = (O(N) + O(N) + O(N) + O(N)) => O(N)
// Where N is the nunber of vertices in the graph and E is the number of edges
// 1st = https://www.youtube.com/watch?v=2rjZH0-2lhk&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=25

class Solution{
    private:
    int dfs(vector<int> adj[], int node, int parent, vector<int> &visited, vector<int> &insertionTime, vector<int> &lowTime, int &timer, int c, int d){
        
        visited[node] = 1;
        insertionTime[node] = lowTime[node] = timer++;
        
        for(auto adjacentNode : adj[node]){
            if(adjacentNode == parent) continue;
            
            if(!visited[adjacentNode]){
                if(dfs(adj, adjacentNode, node, visited, insertionTime, lowTime, timer, c, d)) return 1;
                lowTime[node] = min(lowTime[node], lowTime[adjacentNode]);
                
                if(lowTime[adjacentNode] > insertionTime[node] && ((node == c || node == d) && (adjacentNode == d || adjacentNode == c))){
                    return 1;
                }
            }
            else{
                lowTime[node] = min(lowTime[node], insertionTime[adjacentNode]);
            }
        }
        
        return 0;
    }
    
	public:
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int v, vector<int> adj[], int c, int d){
        vector<int> visited(v, 0), insertionTime(v, -1), lowTime(v, -1);
        int timer = 0;
        for(int i = 0; i < v; i++){
            if(!visited[i]){
                if(dfs(adj, i, -1, visited, insertionTime, lowTime, timer, c, d)) return 1;
            }
        }
        
        return 0;
    }
};
