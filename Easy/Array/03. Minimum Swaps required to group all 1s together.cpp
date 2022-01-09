
// Que 03). Minimum Swaps required to group all 1s together
// Que Link :- https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-group-all-1s-together2451/1/#

// Implementation

// https://www.geeksforgeeks.org/minimum-swaps-required-group-1s-together/
// using sliding windows technique
// Time Complexity = O(N), Space Complexity = O(1)
int minSwaps(int arr[], int n) {
    int countOne = 0;
    
    for(int itr = 0; itr < n; itr++){
        if(arr[itr]) countOne++;
    }
    
    if(countOne == 0) return -1;
    
    int windowSize = countOne, currCountOne = 0;
    
    for(int itr = 0; itr < windowSize; itr++){
        if(arr[itr]) currCountOne++;
    }
    
    int res = 0;
    res = currCountOne;
    
    for(int itr = 1; itr < n - windowSize+1; itr++){
        if(arr[itr-1]) currCountOne--;
        
        if(arr[itr+windowSize-1]) currCountOne++;
        
        res = max(res, currCountOne);
    }
    
    return windowSize - res;
}
