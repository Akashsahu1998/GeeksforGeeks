
// Que 08). Distance from the Source (Bellman-Ford Algorithm)
// Que Link :- https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/0/?fbclid=IwAR2_lL0T84DnciLyzMTQuVTMBOi82nTWNLuXjUgahnrtBgkphKiYk6xcyJU#

// Implementation

// Using Bellman-Ford Algorithm
// Idea : Relax the edges (N-1) times
// Time Complexity = O(N-1) * O(E)
// Space Complexity = O(N)
// Where N is the nunber of vertices in the graph and E is the number of edges
// https://www.youtube.com/watch?v=75yC1vbS8S8&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=28
class Solution{
	public:
	/*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector <int> bellman_ford(int v, vector<vector<int>> adj, int s) {
        vector<int> distance(v, 100000000);
        
        distance[s] = 0;
        
        for(int i = 1; i < v; i++){
            for(auto a : adj){
                // equation => dis[u] + wt < dis[v]
                if(distance[a[0]] + a[2] < distance[a[1]]){
                    distance[a[1]] = distance[a[0]] + a[2];
                }
            }
        }
        
        return distance;
    }
};
