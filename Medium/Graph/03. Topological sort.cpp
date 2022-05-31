
// Que 03). Topological sort 
// Que Link :- https://practice.geeksforgeeks.org/problems/topological-sort/1#

// Implementation


// Using DFS
// Time Complexity = O(N+E)
// Space Complexity = (O(N) + O(N) + O(N)) => O(N)
// Where N is the nunber of vertices in the graph and E is the number of edges
// https://www.youtube.com/watch?v=Yh6EFazXipA&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=13

class Solution{
    private:
    void dfs(int node, vector<int> &vis, stack<int> &st, vector<int> adj[]){
        vis[node] = 1;
        
        for(auto a : adj[node]){
            if(!vis[a]){
	            dfs(a, vis, st, adj);
	        }
        }
        
        st.push(node);
    }
    
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int v, vector<int> adj[]) {
	    vector<int> vis(v, 0);
	    stack<int> st;
	    
	    for(int i = 0; i < v; i++){
	        if(!vis[i]){
	            dfs(i, vis, st, adj);
	        }
	    }
	    
	    vector<int> res;
	    while(!st.empty()){
	        res.push_back(st.top());
	        st.pop();
	    }
	    
	    return res;
	}
};
