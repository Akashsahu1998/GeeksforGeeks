
// Que 01). Binary Search . 
// Que Link :- shorturl.at/hGK15

// Implementation
// Time Complexity = O(LogN), Space Complexity = O(1)

int binarysearch(int arr[], int n, int k){
    int low = 0, high = n-1;
    
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == k) return mid;
        if(arr[mid] < k) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
