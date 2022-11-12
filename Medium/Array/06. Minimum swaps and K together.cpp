
// Que 06). Minimum swaps and K together
// Que Link :- https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article


// Implementation

// Using Window Sliding & Two-Pointer Technique
// Time Complexity : O(N)
// SpaceComplexity : O(1)
class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        // trying to find the window size on which we will be iterating further
        // count number of elements less than equals to k
        int cntMinElements = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] <= k) cntMinElements++;
        }
        
        // find big elements than k in current window of size cntMinElements
        int cntGreaterElements = 0;
        for(int i = 0; i < cntMinElements; i++){
            if(arr[i] > k) cntGreaterElements++;
        }
        
        // trying to find the swap for all windows
        int minSwap = cntGreaterElements;
        for(int i = 0, j = cntMinElements; j < n; i++, j++){
            
            // decrement count of previous window
            if(arr[i] > k) cntGreaterElements--;
            
            // increment count of previous window
            if(arr[j] > k) cntGreaterElements++;
            
            // always take the minimum of swap
            minSwap = min(minSwap, cntGreaterElements);
        }
        
        return minSwap;
    }
};

// Algo Steps
// 1) Find the count of all elements which are less than or equal to ‘k’. Let’s say the count is ‘cntMinElements’
// 2) Using the two-pointer technique for a window of length ‘cntMinElements’, each time keep track of how many elements in this range are greater than ‘k’. Let’s say the total count is ‘cntGreaterElements’.
// 3) Repeat step 2, for every window of length ‘cnt’ and take a minimum of count ‘cntGreaterElements’ among them. This will be the final answer.
