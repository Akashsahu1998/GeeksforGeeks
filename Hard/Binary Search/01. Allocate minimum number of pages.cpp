
// Que 01). Allocate minimum number of pages
// Que Link :- https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1#

// Implementation
// Time Complexity = O(NLogN), Space Complexity = O(1)

class Solution 
{
    public:
    bool isPossible(int arr[], int n, int m, int mid){
        int studentCount = 1, pagesCount = 0;
        for(int itr = 0; itr < n; itr++){
            if(arr[itr] + pagesCount <= mid){
                pagesCount += arr[itr];
            }
            else{
                studentCount++;
                if(studentCount > m || arr[itr] > mid){
                    return false;
                }
                pagesCount = arr[itr];
            }
        }
        return true;
    }
    
    //Function to find minimum number of pages.
    int findPages(int arr[], int n, int m) 
    {
        int low = INT_MAX;
        int high = 0, ans = -1;
        
        for(int itr = 0; itr < n; itr++){
            low = min(low, arr[itr]);
            high += arr[itr];
        }
        
        while(low <= high){
            int mid = (low + high) / 2;
            if(isPossible(arr, n, m, mid)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};
