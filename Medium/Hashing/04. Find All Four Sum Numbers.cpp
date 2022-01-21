
// Que 04). Find All Four Sum Numbers 
// Que Link :- https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1

// Implementation

// using two for loop & 2 pointer's approach
// Time Complexity = O(N^3)
// Space Complexity = O(1), not assuming vector of vector for result, bcz that's a part of output and we are returning that
class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        int n = arr.size();
        
        // taking res vector to store the result
        vector<vector<int> > res;
        
        // sort the array
        sort(arr.begin(), arr.end());
        
        for(int itr = 0; itr <= n-4; itr++){
            for(int jtr = itr+1; jtr <= n-3; jtr++){
                
                // storing two sum using itr & jtr
                long long twoSum = arr[itr] + arr[jtr];
                
                // using two pointers approach
                int left = jtr+1, right = n-1;                
                while(left < right){
                    
                    // storing four sum using twoSum, left & right
                    // taking long long for this case, i.e = arr = [1000000000,1000000000,1000000000,1000000000], k = 0
                    long long fourSum = twoSum + arr[left] + arr[right];
                    
                    // if fourSum is greater than k, then decrement right
                    if(fourSum > k){
                        right--;
                    }   // if fourSum is less than k, then increment left
                    else if(fourSum < k){
                        left++;
                    }
                    else{   // if fourSum is equal to k then store all the four elements into result
                        vector<int> quadruplets = {arr[itr], arr[jtr], arr[left], arr[right]};
                        res.push_back(quadruplets);
                        
                        // suppose there are duplicates, so we need to move ahead our left and right from there, i.e = [1,1,1,2,2,3,3,4,4,4]
                        while(left < right && quadruplets[2] == arr[left]) left++;
                        
                        while(left < right && quadruplets[3] == arr[right]) right--;
                    }
                }
                
                // here also we need to move jtr ahead, bcz duplicates can be present here, i.e = [1,1,1,2,2,3,3,4,4,4]
                while(jtr+1 < n && arr[jtr+1] == arr[jtr]) jtr++;
            }
            
            // here also we need to move itr ahead, bcz duplicates can be present here, i.e = [1,1,1,2,2,3,3,4,4,4]
                while(itr+1 < n && arr[itr+1] == arr[itr]) itr++;
        }
        return res;
    }
};
