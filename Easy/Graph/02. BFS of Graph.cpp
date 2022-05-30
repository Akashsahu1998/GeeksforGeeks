
// Que 02). BFS of Graph
// Que Link :- https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1#

// Implementation

// Using BFS
// https://www.youtube.com/watch?v=UeE67iCK2lQ&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=6
// Time Complexity = O(V+E), Where V is the vertices and E is the edges of the graph
// Space Complexity = O(V)

class Solution{
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int v, vector<int> adj[]) {
        vector<int> bfsResult;
        vector<int> visited(v);
        
        // this upper for loop will handle the case of disconnected grapha as well
        // currently in this problem only connected graph is given that's why commenting it
        // for(int i = 0; i < visited.size(); i++){
        //     if(!visited[i]){
                visited[0] = 0;
                queue<int> bfs;
                bfs.push(0);
                
                while(!bfs.empty()){
                    int node = bfs.front();
                    bfs.pop();
                    bfsResult.push_back(node);
                    
                    for(auto a : adj[node]){
                        if(!visited[a]){
                            visited[a] = 1;
                            bfs.push(a);
                        }
                    }
                }
        //     }
        // }
        
        return bfsResult;
    }
};

