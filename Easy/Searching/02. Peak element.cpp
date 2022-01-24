
// Que 02). Peak element
// Que Link :- https://practice.geeksforgeeks.org/problems/peak-element/1

// Implementation


// 1st Approach
// Brute Force
// Traversing the whole array
// Time Complexity = O(N)
// Space Complexity = O(1)
class Solution
{
    public:
    int peakElement(int arr[], int n){
       for(int itr = 1; itr < n; itr++){
       if(itr == n-1){
           if(arr[itr-1] < arr[itr])
            return itr;
       }
       else{
           if(arr[itr-1] < arr[itr] && arr[itr] > arr[itr+1])
            return itr;
        }
       }
       return 0;
    }
};
