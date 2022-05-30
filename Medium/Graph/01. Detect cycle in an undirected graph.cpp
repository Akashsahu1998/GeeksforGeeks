
// Que 01). Detect cycle in an undirected graph
// Que Link :- https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1/#

// Implementation

// 1st Approach
// Using BFS
// https://www.youtube.com/watch?v=UeE67iCK2lQ&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=6
// Time Complexity = O(V+E), Where V is the vertices and E is the edges of the graph
// Space Complexity = O(V)

class Solution{
  private:
    bool isThereCycleInTheGraph(vector<int> adj[], vector<int> &visited, int node){
        // pair of node and its prev node
        queue<pair<int, int>> q;
        
        // currently there is no previous so -1
        q.push({node, -1});
        visited[node] = 1;
        
        while(!q.empty()){
            int frontNode = q.front().first;
            int prevNode = q.front().second;
            q.pop();
            
            for(auto a : adj[frontNode]){
                if(!visited[a]){
                    visited[a] = 1;
                    q.push({a, frontNode});                    
                }
                else{
                    if(a != prevNode) return true;
                }
            }
        }
        
        return false;
    }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int v, vector<int> adj[]) {
        vector<int> visited(v);
        
        // Starting from 0, bcz node can have 0 as well, in the example we can see
        for(int i = 0; i < visited.size(); i++){
            if(!visited[i]){
                if(isThereCycleInTheGraph(adj, visited, i)) return true;
            }
        }
        return false;
    }
};


// 2nd Approach
// Using DFS
// https://www.youtube.com/watch?v=Y9NFqI6Pzd4&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=9
// Time Complexity = O(V+E), Where V is the vertices and E is the edges of the graph
// Space Complexity = O(V)
class Solution{
private:
    bool isThereCycleInTheGraph(int node, int parent, vector<int> adj[], vector<int> &visited){
        visited[node]= true;
        
        for(auto a: adj[node]){
            if(!visited[a]){
                if(isThereCycleInTheGraph(a, node, adj, visited)){
                    return true;
                }
            }
            else if(visited[a] && a != parent) return true;
        }
        return false;
    }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int v, vector<int> adj[]) {
        vector<int> visited(v);
        
        // Starting from 0, bcz node can have 0 as well, in the example we can see
        for(int i = 0; i < visited.size(); i++){
            if(!visited[i]){    
                if(isThereCycleInTheGraph(i, -1, adj, visited)) return true;
            }
        }
        return false;
    }
};
