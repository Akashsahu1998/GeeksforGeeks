
// Que) 01. Maximum of minimum for every window size 
// Que Link :- https://practice.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1

// Implementation

// Naive Approach
// Giving TLE
// using dequeue
// Time Complexity : (O(N^2) + O(N)) => O(N^2),  N(Windows size) * N(All elements we are iterating) = O(N^2) and and N element we are inserting & deleting in queue
// Space Complexity : O(K), max to max only K elements we are putting into dequeue, we are not considering res bcz its for output
class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n){
        vector<int> res;
        
        for(int itr = 0; itr < n; itr++){
            int k = itr+1;
            int maxValue = INT_MIN;
            deque<int> dq;
            for(int jtr = 0; jtr < n; jtr++){
                if(!dq.empty() && dq.front() == jtr-k) dq.pop_front();
                
                while(!dq.empty() && arr[dq.back()] > arr[jtr]) dq.pop_back();
                
                dq.push_back(jtr);
                
                if(jtr >= k-1) maxValue = max(maxValue, arr[dq.front()]);
            }
            res.push_back(maxValue);
        }
        return res;
    }
};
