
// Que 01). Missing number in array
// Que Link :- https://practice.geeksforgeeks.org/problems/missing-number-in-array1416/1

// Implementation

// Time Complexity = O(N)
// Space Complexity = O(1)
class Solution{
  public:
    int MissingNumber(vector<int>& arr, int n) {
        
        // find the total sum of elements from 1 to n
        int totalSum = (n * (n+1)) / 2, sum = 0;
        
        // store the sum of all elements into arr
        for(int itr = 0; itr < arr.size(); itr++){
            sum += arr[itr];
        }
        
        // return the totalSum - sum, bcz the difference is a number which is missed from an array
        return totalSum - sum;
    }
};
