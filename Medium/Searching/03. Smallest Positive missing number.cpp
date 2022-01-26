
// Que 03). Smallest Positive missing number
// Que Link :- https://practice.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1

// Implementation

// Efficient Solution
// Time Complexity = O(N)
// Space Complexity = O(1)
class Solution{
    public:
    // Function to find missing integer in array
    // arr: input array
    // n: size of array
    int findMissing(int arr[], int n) { 
        
        for(int itr = 0; itr < n; itr++){
            
            // idea is to put all the elements into their equal index, i.e 2 will be on 2nd index, like this
            // neglect all numbers which are less than 1, and all numbers which are greater than 1, and
            // if current arr[itr] is not equal to (arr[arr[itr] - 1]) value, then do swap
            // with this (arr[itr] != arr[arr[itr] - 1]) also handling the case i.e [1,1]
            // its 0 based indexing that's why using arr[itr] - 1             
            while((arr[itr] >= 1 && arr[itr] <= n) && (arr[itr] != arr[arr[itr] - 1])){
                int pos = arr[itr] - 1;                
                swap(arr[itr], arr[pos]);
            }
        }
        
        // checking if any element is not equal to their current index then it means that element is missing
        for(int itr = 0; itr < n; itr++){
            if(itr+1 != arr[itr]) return itr+1;
        }
        
        // returning n+1 bcz, i.e = [1,2,3] then ans will be 4 only
        return n+1;
    }
};
