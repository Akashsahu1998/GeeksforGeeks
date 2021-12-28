
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


// Efficient Approach
// Traversing 5 times
// Time Complexity : O(N)
// Space Complexity : O(N) bcz we used stack
class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n){
        stack<int> st;
        
        // creating the left arr which contains a previous smaller element which
        // is the nearest smallest element on the left side of arr[i]. 
        vector<int> left(n);
        for(int itr = 0; itr < n; itr++){
            while(!st.empty() && arr[st.top()] >= arr[itr]) st.pop();
            
            if(st.empty()) left[itr] = -1;
            else left[itr] = st.top();
            
            st.push(itr);
        }
        
        // clearing the stack
        while(!st.empty()) st.pop();
        
        // creating the right arr which contains a next smaller element which
        // is the nearest smallest element on the right side of arr[i]. 
        vector<int> right(n);
        for(int itr = n-1; itr >= 0; itr--){
            while(!st.empty() && arr[st.top()] >= arr[itr]) st.pop();
            
            if(st.empty()) right[itr] = n;
            else right[itr] = st.top();
            
            st.push(itr);
        }
        
        // Once we have indexes of next and previous smaller, we know that
        // arr[i] is a minimum of a window of length (right[i] - left[i] - 1)
        
        // create ans of n+1 size
        vector<int> ans(n+1, 0);
        
        for(int itr = 0; itr < n; itr++){
            int len = right[itr] - left[itr] - 1;
            ans[len] = max(ans[len], arr[itr]);
        }
        
        // Some entries in ans[] are 0 and yet to be filled
        // bcz there can we an element which is equal to another smaller element
        for(int itr = n-1; itr > 0; itr--){
            ans[itr] = max(ans[itr], ans[itr+1]);
        }
        
        // copying all elements from and to res
        vector<int> res;
        for(int itr = 1; itr < n+1; itr++){
            res.push_back(ans[itr]);
        }
        
        return res;
    }
};
