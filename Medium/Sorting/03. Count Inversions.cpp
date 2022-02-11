
// Que 03). Count Inversions 
// Que Link :- https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1/#

// Implementation

// Using Merge Sort
// Time Complexity = O(NLogN)
// Space Complexity = O(N)

class Solution{
    public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    // merging the array into ascending order and counting the inversion count
    long long int mergeArrAndCountInversion(long long arr[], long long tempMergeArr[], long long int  start, long long int  mid, long long int  end){
        long long int left = start, right = mid+1, index = start;
        long long int countInversion = 0;
        
        while(left <= mid and right <= end){
            if(arr[left] > arr[right]){
                countInversion += mid - left + 1;
                tempMergeArr[index++] = arr[right++];
            }
            else{
                tempMergeArr[index++] = arr[left++];
            }
        }
        
        while(left <= mid) tempMergeArr[index++] = arr[left++];
        
        while(right <= end) tempMergeArr[index++] = arr[right++];
        
        for(int itr = start; itr <= end; itr++)
            arr[itr] = tempMergeArr[itr];
            
        return countInversion;
    }
    
    // merge sort function for recusrion calls
    long long int mergeSort(long long arr[], long long temp[], long long int  start, long long int  end){
        long long int countInversion = 0;
        if(start < end){
            long long int  mid = start + (end - start)/2;
            
            countInversion += mergeSort(arr, temp, start, mid);
            countInversion += mergeSort(arr, temp, mid+1, end);
            
            countInversion += mergeArrAndCountInversion(arr, temp, start, mid, end);
        }
        return countInversion;
    }
    
    long long int inversionCount(long long arr[], long long N){
        long long temp[N];
        return mergeSort(arr, temp, 0, N-1);
    }
};
