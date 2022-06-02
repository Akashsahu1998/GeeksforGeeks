
// Que 07). Strongly Connected Components (Kosaraju's Algo) 
// Que Link :- https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1/#

// Implementation

// Using Topological Sort & Transposing of the graph
// Time Complexity = O(N+E)
// Space Complexity = (O(N) + O(N) + O(N+E)) => O(N+E)
// Where N is the nunber of vertices in the graph and E is the number of edges
// https://www.youtube.com/watch?v=V8qIqJxCioo&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=27
class Solution{
    private:
    void dfsTopologicalSort(vector<int> adj[], vector<int> &visited, int node, stack<int> &st){
        visited[node] = 1;
        
        for(auto a : adj[node]){
            if(!visited[a]){
                dfsTopologicalSort(adj, visited, a, st);
            }
        }
        
        st.push(node);
    }
    
    void dfsCountStronglyConnectedComponents(vector<int> transpose[], vector<int> &visited, int node){
        visited[node] = 1;
        
        for(auto a : transpose[node]){
            if(!visited[a]){
                dfsCountStronglyConnectedComponents(transpose, visited, a);
            }
        }
    }
    
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int v, vector<int> adj[]){
        vector<int> visited(v, 0);
        
        // store the graphs according to its finishing time, basically topological sort
        stack<int> st;
        for(int i = 0; i < v; i++){
            if(!visited[i]){
                dfsTopologicalSort(adj, visited, i, st);
            }
        }
        
        // transpose the graph, pushing i value into ath index of the transpose graph
        vector<int> transpose[v];
        for(int i = 0; i < v; i++){
            
            // putting 0 bcz at the time of topological sort all graph got visited, so marking it non visited again.
            visited[i] = 0;
            for(auto a : adj[i]){
                transpose[a].push_back(i);
            }
        }
        
        int res = 0;
        
        // count the nodes according to their finishing time, same as topological sort
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(!visited[node]){
                dfsCountStronglyConnectedComponents(transpose, visited, node);
                res++;
            }
        }
        
        return res;
    }
};
