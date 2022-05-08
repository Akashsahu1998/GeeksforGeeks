
// Que 01). Minimum Platforms
// Que Link :- https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#

// Implementation

// Using Sorting
// Time Complexity = O(NLogN)
// Space Complexity = O(1)

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n){
    	sort(arr, arr + n);
    	sort(dep, dep + n);
    	
    	int curPlatform = 0, maxPlatform = 0, i = 0, j = 0;
    	while(i < n && j < n){
    	    if(dep[j] < arr[i]){
    	        j++;
    	        curPlatform--;
    	    }
    	    else{
    	        i++;
    	        curPlatform++;
    	    }
    	    
    	    maxPlatform = max(maxPlatform, curPlatform);
    	}
    	
    	return maxPlatform;
    }
};
