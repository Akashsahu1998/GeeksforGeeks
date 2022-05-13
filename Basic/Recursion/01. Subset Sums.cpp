
// Que) 01. Subset Sums
// Que Link :- https://practice.geeksforgeeks.org/problems/subset-sums2234/1#

// Implementation

// 1st Approach
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



// 2nd Approach
// Using Recursion
// Time Complexity : O(2^n)
// Space Complexity : O(2^n)
class Solution{
private:
    void calculateSubsets(vector<int> &res, vector<int> arr, int index, int sum){
        res.push_back(sum);
        
        for(int i = index; i < arr.size(); i++){
            calculateSubsets(res, arr, i+1, sum+arr[i]);
        }
    }

public:
    vector<int> subsetSums(vector<int> arr, int N){
        vector<int> res;
        calculateSubsets(res, arr, 0, 0);
        return res;
    }
};



// 3rd Approach
// Iterative Approach
// Time Complexity: O(N * 2^N)
// Space Complexity: O(2^N)
class Solution{
public:
    vector<int> subsetSums(vector<int> arr, int N){
        vector<int> res;
        res.push_back({});
        
        for(int i = 0; i < arr.size(); i++){            
            int resSize = res.size();            
            for(int j = 0; j < resSize; j++){
                int sum = res[j];
                sum += arr[i];
                res.push_back(sum);
            }
        }        
        return res;
    }
};
