
// Que 07).  Positive Negative Pair 
// Que Link :- https://practice.geeksforgeeks.org/problems/pairs-with-positive-negative-values3719/1

// Implementation

// Using unoredered_map
// Time Complexity = O(N), Space Complexity = O(N)
class Solution{
  public:
    //Function to return list containing all the pairs having both
    //negative and positive values of a number in the array.
    vector <int> findPairs(int arr[], int n) {
        // taking an map to store the presence of a val
        unordered_map<int, int> mp;
        vector<int> res;
        
        // iterating over the elements
        for(int itr = 0; itr < n; itr++){
            int val = arr[itr];
            
            // val is positive then in map we are checking negative value is present or not
            // val is negative then in map we are checking positive value is present or not
            // if negative or positive value is present into the mp then push both values into res and erase both values as well
            if(mp[-val]){
                mp[-val]--;
                val = abs(val);
                // push abs value into res two times
                res.push_back(-val);
                res.push_back(val);
            }   // if not present into map, then simply add the value
            else{
                mp[val]++;
            }
        }
        return res;
    }
};
