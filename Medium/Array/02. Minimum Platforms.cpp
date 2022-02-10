
// Que 02). Minimum Platforms
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
    	sort(arr, arr+n);
    	sort(dep, dep+n);
    	
    	int trainComingPtr = 1, trainGoingPtr = 0, maxPlatforms = 1, curPlatforms = 1;
    	
    	while(trainComingPtr < n){
    	    if(arr[trainComingPtr] <= dep[trainGoingPtr]) {
    	        curPlatforms++;
    	        trainComingPtr++;
    	    }
    	    else{
    	        trainGoingPtr++;
    	        curPlatforms--;
    	    }
    	    
    	    maxPlatforms = max(maxPlatforms, curPlatforms);
    	}
    	return maxPlatforms;
    }
};
