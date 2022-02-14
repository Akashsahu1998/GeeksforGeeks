
// Que) 01. Merge Without Extra Space
// Que Link :- https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1#

// Implementation

// Naive Approach
// Time Complexity : O(n * m)
// Space Complexity : O(1)
class Solution{
    public:
    //Function to merge the arrays.
    void merge(long long arr1[], long long arr2[], int n, int m) { 
        
        // take two pointers, itr will point to nums1, and jtr will point to nums2
        int itr = 0, jtr = 0;
        
        while(itr < n && jtr < m){
            // if nums[itr] is greater than nums2[jtr], then swap each other
            if(arr1[itr] > arr2[jtr]) swap(arr1[itr], arr2[jtr]);
            
            // always increment itr by 1
            itr++;
            
            // maintain the sorted order of nums2, bcz we are swapping values, so it can happen that, nums2 can loose it sorted order, so we need to check it and maintain it everytime
            if(jtr+1 < m && arr2[jtr] > arr2[jtr+1]){
                int ktr = jtr;
                while(ktr+1 < m && arr2[ktr] > arr2[ktr+1]){
                    swap(arr2[ktr++], arr2[ktr+1]);
                }
            }
        }
    }
};
