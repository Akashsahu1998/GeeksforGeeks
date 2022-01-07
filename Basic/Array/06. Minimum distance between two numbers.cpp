
// Que 06). Minimum distance between two numbers
// Que Link :- https://practice.geeksforgeeks.org/problems/minimum-distance-between-two-numbers/1

// Implementation

// Time Complexity = O(N), Space Compelxity = O(1)
class Solution{
  public:
    int minDist(int arr[], int n, int x, int y) {
        int dist1 = -1, dist2 = -1;
        int minDist = INT_MAX;
        for(int itr = 0; itr < n; itr++){
            if(arr[itr] == x || arr[itr] == y){
                if(arr[itr] == x) dist1 = itr;
                else dist2 = itr;
                
                if(dist1 != -1 && dist2 != -1)
                    minDist = min(minDist, abs(dist1 - dist2));
            }
        }
        return (dist1 == -1 || dist2 == -1) ? -1 : minDist;
    }
};
