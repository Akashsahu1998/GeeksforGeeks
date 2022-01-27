
// Que 01). Merge Sort
// Que Link :- https://practice.geeksforgeeks.org/problems/merge-sort/1

// Implementation

// Time Complexity = O(NLogN)
// Space Complexity = O(N)
class Solution{
    public:
    // Time Complexity = O(N)
    // Space Complexity = O(N)
    public:
    void merge(int arr[], int l, int mid, int r){
         int len1 = mid - l + 1;
         int len2 = r - mid;
         
         vector<int> leftArr(len1), rightArr(len2);
         
         // copy values into left array
         int arrIndex = l;
         for(int itr = 0; itr < len1; itr++){
             leftArr[itr] = arr[arrIndex++];
         }
         
         // copy values into right array
         arrIndex = mid + 1;
         for(int itr = 0; itr < len2; itr++){
             rightArr[itr] = arr[arrIndex++];
         }
         
         // merge two sorted array
         arrIndex = l;
         int leftArrIndex = 0, rightArrIndex = 0;
         while(leftArrIndex < len1 && rightArrIndex < len2){
             if(leftArr[leftArrIndex] < rightArr[rightArrIndex]){
                 arr[arrIndex++] = leftArr[leftArrIndex++];
             }
             else{
                 arr[arrIndex++] = rightArr[rightArrIndex++];
             }
         }
         
         // adding remaining element of left array
         while(leftArrIndex < len1){
             arr[arrIndex++] = leftArr[leftArrIndex++];
         }
         
         // adding remaining element of right array
         while(rightArrIndex < len2){
             arr[arrIndex++] = rightArr[rightArrIndex++];
         }
    }
    
    // Time Complexity = O(LogN)
    // Space Complexity = O(1)
    public:
    void mergeSort(int arr[], int l, int r){
        if(l >= r){
            return;
        }
        
        // finding the mid
        int mid = l - (l - r)/2;
        
        // sort left part
        mergeSort(arr, l, mid);
        
        // sort right part
        mergeSort(arr, mid+1, r);
        
        // merge the left & right part
        merge(arr, l, mid, r);
    }
};

