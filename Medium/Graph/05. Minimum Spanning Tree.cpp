
// Que 05). Minimum Spanning Tree
// Que Link :- https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1/#

// Implementation

// 1st Approach
// Using BFS, Prim's Algorithm
// Time Complexity = O(N+E) + O(NLogN)
// Space Complexity = (O(N) + O(N) + O(N) + O(N)) => O(N)
// Where N is the nunber of vertices in the graph and E is the number of edges
// 1st = https://www.youtube.com/watch?v=xsM8i0jVF1w&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=19
// 2nd = https://www.youtube.com/watch?v=HnD676J56ak&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=21
// 3rd = https://www.youtube.com/watch?v=oNTsS8lGDHw&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=21

class Solution{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[]){
        vector<int> key(v, INT_MAX);
        vector<bool> mst(v, false);
        vector<int> parent(v, -1);
        
        // to create min heap
        // data type, vector, comparison
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        key[0] = 0;
        
        // {weight, key}
        pq.push({0, 0});
        
        while(!pq.empty()){
            int node = pq.top().second;
            pq.pop();
            
            mst[node] = true;
            
            for(auto a : adj[node]){
                
                int aNode = a[0];
                int aDisWeight = a[1];
                
                if(mst[aNode] == false && aDisWeight < key[aNode]){
                    parent[aNode] = node;
                    key[aNode] = aDisWeight;
                    pq.push({key[aNode], aNode});
                }
            }
        }
        
        int res = 0;
        for(auto a : key){
            res += a;
        }
        
        return res;
    }
};
