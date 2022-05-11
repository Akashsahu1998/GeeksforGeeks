
// Que 02). Fractional Knapsack
// Que Link :- https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1#

// Implementation

// Using Sorting & Greedy
// Time Complexity: O(N log N)
// Space Complexity: O(1)
class Solution
{
    public:
    
    bool static comp(Item item1, Item item2){
        return ((double)item1.value/(double)item1.weight) > ((double)item2.value/(double)item2.weight);
    }
    
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n){
        sort(arr, arr+n, comp);
        
        double total = 0.0;
        for(int i = 0; i < n; i++){
            if(w - arr[i].weight >= 0){
                w -= arr[i].weight;
                total += arr[i].value;
            }
            else{
                total += ((double)arr[i].value / (double)arr[i].weight) * (double)w;
                break;
            }
        }
        
        return total;
    }
        
};
