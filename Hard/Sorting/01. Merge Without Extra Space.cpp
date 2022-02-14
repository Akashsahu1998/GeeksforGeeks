
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
        
        // take two pointers, itr will point to arr1, and jtr will point to arr2
        int itr = 0, jtr = 0;
        
        while(itr < n && jtr < m){
            // if arr1[itr] is greater than arr2[jtr], then swap each other
            if(arr1[itr] > arr2[jtr]) swap(arr1[itr], arr2[jtr]);
            
            // always increment itr by 1
            itr++;
            
            // maintain the sorted order of arr2, bcz we are swapping values, so it can happen that, arr2 can loose it sorted order, so we need to check it and maintain it everytime
            if(jtr+1 < m && arr2[jtr] > arr2[jtr+1]){
                int ktr = jtr;
                while(ktr+1 < m && arr2[ktr] > arr2[ktr+1]){
                    swap(arr2[ktr++], arr2[ktr+1]);
                }
            }
        }
    }
};


// Efficient Approach
// Time Complexity : O(N+M) + O(NlogN) + O(MlogM) => O((N+M)log(N+M))
// Space Complexity : O(1)
class Solution{
    public:
    
    //Function to merge the arrays.
    void merge(long long arr1[], long long arr2[], int n, int m) { 
        
        // take 3 pointers, itr will point to arr1, and jtr will point to arr2, and ktr will start from arr1 end
        int itr = 0, jtr = 0, ktr = n - 1;
   
        // run till itr is less than equal to ktr, and jtr is less than m
        while (itr <= ktr && jtr < m) {
            
            // we are doing this, bcz we know the fact that both arr are sorted
            // if arr1[itr] is greater than arr2[jtr], then just increment itr by 1
            if (arr1[itr] < arr2[jtr])
                itr++;
            else {  // otherwise just swap arr1[ktr] and arr2[jtr], and decrement ktr by 1 & increment jtr by 1
                swap(arr2[jtr++], arr1[ktr--]);
            }
        }
       
        // Sort first array
        sort(arr1, arr1 + n);
       
        // Sort second array
        sort(arr2, arr2 + m);
    }
};
