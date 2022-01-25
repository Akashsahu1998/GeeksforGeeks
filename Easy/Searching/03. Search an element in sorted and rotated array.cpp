
// Que 03). Search an element in sorted and rotated array
// Que Link :- https://practice.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1

// Implementation


// Using Binary Search
// Time Complexity = O(LogN), Space Complexity = O(1)
int Search(vector<int> arr, int key) {
    int low = 0, high = arr.size()-1;
    
    while(low <= high){
        int mid = low + (high-low)/2;
        
        if(key == arr[mid]) return mid;
        
        // if left part is sorted, otherwise go into the else
        if(arr[low] <= arr[mid]){
            if(arr[low] <= key && key <= arr[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        else{
            if(arr[mid] <= key && key <= arr[high]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
    }
    
    return -1;
}
