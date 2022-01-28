
// Que 02). Quick Sort
// Que Link :- https://practice.geeksforgeeks.org/problems/quick-sort/1

// Implementation

// Best Case
// Time Complexity = O(NLogN)
// Space Complexity = O(logN)

// Avg Case
// Time Complexity = O(LogN)
// Space Complexity = O(N)

// Worst Case
// Time Complexity = O(N^2)
// Space Complexity = O(N)

class Solution{
    public:    
    // Time Complexity = O(LogN)
    // Space Complexity = O(N)
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high){
            if(low < high){
            
            // placing the privot at correct index and doing the partition
            int pivotIndex = partition(arr, low, high);
            
            // calling the left half of the partition
            quickSort(arr, low, pivotIndex-1);
            
            // calling the right half of the partition
            quickSort(arr, pivotIndex+1, high);
        }
    }
    
    // Time Complexity = O(N)
    // Space Complexity = O(1)
    public:
    int partition (int arr[], int low, int high){
       // taking mid as a privot
       int pivot = arr[low];
       int itr = low, jtr = high;
       
       // moving until and unless jtr is greater than itr
       while(itr < jtr){
           
           // moving itr until & unless the element at index itr is greater than pivot
           while(arr[itr] <= pivot) itr++;
           
           // moving jtr until & unless the element at index jtr is smaller than pivot
           while(arr[jtr] > pivot) jtr--;
           
           // if itr is less than jtr, then swap
           if(itr < jtr) swap(arr[itr], arr[jtr]);
       }
       
       // swap the low and jtr index values, bcz we need to place pivot at correct place
       swap(arr[low], arr[jtr]);
       
       // returning jtr means we are partioning into left and right half from this index
       return jtr;
    }
};
