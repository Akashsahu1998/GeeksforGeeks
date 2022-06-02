
// Que 01). Articulation Point - I 
// Que Link :- https://practice.geeksforgeeks.org/problems/articulation-point-1/0/#

// Implementation

// Using DFS
// Time Complexity = O(N+E)
// Space Complexity = (O(N) + O(N) + O(N) + O(N)) => O(N)
// Where N is the nunber of vertices in the graph and E is the number of edges
// 1st = https://www.youtube.com/watch?v=3t3JHswP7mw&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=27
class Solution {
  private:
    void dfs(int node, int parent, int &timer, vector<int> &lowTime, vector<int> &insertionTime, vector<int>adj[], vector<int> &res){
        
        lowTime[node] = insertionTime[node] = timer++;
        int child = 0;
        
        for(auto adjacentNode: adj[node]){
            if(adjacentNode == parent) continue;
            
            if(lowTime[adjacentNode] == -1){
                
                dfs(adjacentNode, node, timer, lowTime, insertionTime, adj, res);
                lowTime[node] = min(lowTime[adjacentNode], lowTime[node]);
                 
                if(lowTime[adjacentNode] >= insertionTime[node] && parent != -1){
                    res[node] = 1;
                }
                    
                child++;
            }
            else{
                lowTime[node] = min(lowTime[node], insertionTime[adjacentNode]);
            }
        }
            
        if(parent == -1 && child > 1){
            res[node] = 1;
        }
    }
    
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        
        // will be using lowTime as a visited array
        vector<int> lowTime(V, -1), insertionTime(V, -1), res(V, 0), finalRes;
        
        int timer = 0;
        for(int i = 0; i < V; i++){
            if(lowTime[i] == -1){
                dfs(i, -1, timer, lowTime, insertionTime, adj, res);
            }
        }
        
        for(int i = 0; i < V; i++){
            if(res[i]){
                finalRes.push_back(i);
            }
        }
        if(finalRes.size() == 0) finalRes.push_back(-1);
        return finalRes;
    }
};
