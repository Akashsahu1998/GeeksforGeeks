
// Que 01). Circular tour
// Que Link :- https://practice.geeksforgeeks.org/problems/circular-tour/1

// Implementation

// Time Complexity = O(N^2), Space Complexity = O(1)
// We are visiting each petrol pump exactly once, therefore the time complexity is O(n)
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n){
       int start = 0, dist = 0, total = 0, count = 0, itr = 0;
       
       while(count != n){
           int total = total + p[itr%n].petrol;
           int dist = p[itr%n].distance;
           
           if(total < dist){
               start = itr+1;
               total = 0;
               dist = 0;
               count = 0;
               if(start >= n) return -1;
           }
           else {
               count++;
               total -= dist;
           }
           
           itr++;
       }
       
       return start;
    }
};
