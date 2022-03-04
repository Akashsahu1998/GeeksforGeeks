
// Que 04). Overlapping Intervals 
// Que Link :- https://practice.geeksforgeeks.org/problems/8a644e94faaa94968d8665ba9e0a80d1ae3e0a2d/1/

// Implementation

// Using Sorting
// Time Complexity: O(NLogN)
// Space Complexity: O(1), not considering the res vector of vector, bcz that's a part of o/p

class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         vector<vector<int>> res;
        
        // sort the vector
        sort(intervals.begin(), intervals.end());
        
        // inserting the 0th index value into tempInterval vector
        // tempInterval it will take constant space, bcz the size of this vector will always remains 2 only
        vector<int> tempInterval = intervals[0];
        
        // iterating from 1, and checking if the current itr index value lies into the interval of tempInterval vector
        // if lies then we will take the maximum value of the end interval, and store into tempInterval[1] position
        // if didn't lies, it means we got the first merged interval, and will store into the res, after that we will put the current itr index value of intervals into tempInterval vector to check the next element
        for(int itr = 1; itr < intervals.size(); itr++){
            if(intervals[itr][0] <= tempInterval[1]){
                tempInterval[1] = max(intervals[itr][1], tempInterval[1]);
            }
            else{
                res.push_back(tempInterval);
                tempInterval = intervals[itr];
            }
        }
        res.push_back(tempInterval);
        
        return res;
    }
};
