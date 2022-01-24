
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


// 2nd Approach
// Efficient Approach
// Using binary search
// Time Complexity = O(LogN)
// Space Complexity = O(1)
int peakElement(int arr[], int n){
   int low = 0, high = n-1;
   
   while(low <= high){
    //   int mid = low + (high - low)/2;
        int mid = (low+high) >> 1;
       
       if((mid == 0 || arr[mid-1] < arr[mid]) && (mid == n-1 || arr[mid] > arr[mid+1])){
           return mid;
       }
       
       // if left element is big, so move towards left
       if(mid > 0 && arr[mid-1] > arr[mid]){
           high = mid-1;
       }
       else{    // else right is big, so move towards right
           low = mid+1;
       }
   }
   return 0;
}
