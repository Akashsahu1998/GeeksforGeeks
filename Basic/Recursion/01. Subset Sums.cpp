
// Que) 01. Subset Sums
// Que Link :- https://practice.geeksforgeeks.org/problems/subset-sums2234/1#

// Implementation

// Using Recursion
// Time Complexity : O(2^n)
// Space Complexity : O(2^n)
class Solution{
private:
    void calculateSubsets(vector<int> &res, vector<int> arr, int index, int sum){
        
        if(index == arr.size()) {
            res.push_back(sum);
            return;
        }
        
        // pick
        calculateSubsets(res, arr, index+1, sum + arr[index]);
        
        // pick not pick
        calculateSubsets(res, arr, index+1, sum);
    }

public:
    vector<int> subsetSums(vector<int> arr, int N){
        vector<int> res;
        calculateSubsets(res, arr, 0, 0);
        return res;
    }
};
