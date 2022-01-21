
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
            
            // if negative or positive value is present into the mp then push both values into res and erase both values as well
            if(mp[val] || mp[-val]){
                val = abs(val);
                res.push_back(-val);
                res.push_back(val);
                mp.erase(val);
                mp.erase(-val);
            }   // if not present into map, then simply add the value
            else{
                mp[val]++;
            }
        }
        return res;
    }
};


// Using unoredered_set
// Time Complexity = O(N), Space Complexity = O(N)
class Solution{
  public:
    //Function to return list containing all the pairs having both
    //negative and positive values of a number in the array.
    vector <int> findPairs(int arr[], int n) {
        // taking an st to store the presence of a val
        unordered_set<int> st;
        vector<int> res;
        
        // iterating over the elements
        for(int itr = 0; itr < n; itr++){
            int val = arr[itr];
            
            // if negative or positive value is present into the st then push both values into res and erase both values as well
            if(st.find(val) != st.end() || st.find(-val) != st.end()){
                val = abs(val);
                res.push_back(-val);
                res.push_back(val);
                st.erase(val);
                st.erase(-val);
            }   // if not present into st, then simply add the value
            else{
                st.insert(val);
            }
        }
        return res;
    }
};
