
// Que 02). Maximum of all subarrays of size k
// Que Link :- https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1

// Implementation

// https://www.youtube.com/watch?v=CZQGRp93K4k&t=153s
// Most Efficient Approach
// using dequeue
// Traversing 1 time
// Time Complexity = (O(N) + O(N)) => O(N),  N elemens we are iterating and N element we are inserting & deleting in queue
// Space Complexity = O(K), max to max only K elements we are putting into dequeue
class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k){
        vector<int> res;
        deque<int> dq;
        for(int itr = 0; itr < n; itr++){
            
            // removing the index which is going out of our window
            if(!dq.empty() && dq.front() == itr-k){
                dq.pop_front();
            }
            
            // pop till the coming element is greater
            while(!dq.empty() && arr[itr] >= arr[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(itr);
            if(itr >= k-1)res.push_back(arr[dq.front()]);
        }
        return res;
    }
};
