
// Que 04). Implementing Dijkstra Algorithm 
// Que Link :- https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1/#

// Implementation

// 1st Approach
// Using BFS, Dijkstra Algorithm
// Time Complexity = O(N + ElogN)
// Space Complexity = (O(N) + O(N)) => O(N)
// Where N is the nunber of vertices in the graph and E is the number of edges
// https://www.youtube.com/watch?v=jbhuqIASjoM&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=18

class Solution{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int s){
        vector<int> distance(v, INT_MAX);
        
        // to create min heap we need to take pass these 3 parameters
        // data type, vector type, comparison
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        distance[s] = 0;
        pq.push({0, s});
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto a : adj[node]){
                int aNode = a[0];
                int aDis = a[1];
                
                if(dis + aDis < distance[aNode]){
                    distance[aNode] = dis + aDis;
                    pq.push({distance[aNode], aNode});
                }
            }
        }
        
        return distance;
    }
};
