
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
           total = total + p[itr%n].petrol;
           dist = p[itr%n].distance;
           
           if(total < dist){
               start = itr+1;
               total = dist = count = 0;
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



// 2nd Approach
// Most Efficient Approach
// Time Complexity = O(N), Space Complexity = O(1)
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n){
       int start = 0, backupTotal = 0, total = 0;
        
        for(int itr = 0; itr < n; itr++){
            backupTotal = backupTotal + p[itr].petrol - p[itr].distance;
            if(backupTotal < 0){
                start = itr+1;
                total += backupTotal;
                backupTotal = 0;
            }
        }      
       
        return (total + backupTotal) >= 0 ? start : -1 ;
    }
};
