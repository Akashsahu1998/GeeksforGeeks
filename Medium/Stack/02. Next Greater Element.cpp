
// Que 01). Next Greater Element
// Que Link :- https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1#

// Implementation

// Using Stack
// Time Complexity = O(N), Space Complexity = O(N)
class Solution
{
    public:    
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        stack<long long> s;
        vector<long long> res;
        for(int itr = n-1; itr >= 0; itr--){
            while(!s.empty() && s.top() < arr[itr]){
                s.pop();
            }
            if(s.empty()) res.push_back(-1);
            else res.push_back(s.top());
            s.push(arr[itr]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
