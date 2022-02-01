
// Que 04). Sort an array of 0s, 1s and 2s 
// Que Link :- https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1


// Implementation

// 1st Approach
// Naive Approach
// Using the inbuilt sort function
// Time Complexity = O(NLogN)
// Space Complexity = O(1)
class Solution{
{
    public:
    void sort012(int a[], int n){
        sort(a, a+n);
    }
    
};


// 2nd Approach
// Efficient Approach
// Traversing 2 times
// Time Complexity = O(N)
// Space Complexity = O(1)
class Solution
{
    public:
    void sort012(int nums[], int n){
        int countZero = 0, countOne = 0, countTwo = 0;
        
        for(int itr = 0; itr < n; itr++){
            if(nums[itr] == 0) countZero++;
            else if(nums[itr] == 1) countOne++;
            else countTwo++;
        }
        
        for(int itr = 0; itr < n; itr++){
            if(itr < countZero) nums[itr] = 0;
            else if(itr < countZero + countOne) nums[itr] = 1;
            else nums[itr] = 2;
        }
    }
};
