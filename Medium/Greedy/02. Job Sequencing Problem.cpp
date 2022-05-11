
// Que 02). Job Sequencing Problem
// Que Link :- https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#

// Implementation

// Using Sorting & Greedy
// Time Complexity: O(N log N) + O(N * M), where N is the length of arr and M is the maximum deadline.
// Space Complexity: O(M)
class Solution 
{
    public:
    
    bool static comp(Job a, Job b){
        return a.profit > b.profit;
    }
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) { 
        sort(arr, arr+n, comp);
        
        int maxDeadline = 0;
        for(int i = 0; i < n; i++){
            maxDeadline = max(maxDeadline, arr[i].dead);
        }
        
        vector<int> dp(maxDeadline+1, -1);
        
        int cnt = 0, total = 0;
        
        for(int i = 0; i < n; i++){
            
            for(int j = arr[i].dead; j > 0; j--){
                if(dp[j] == -1){
                    dp[j] = arr[i].id;
                    cnt++;
                    total += arr[i].profit;
                    break;
                }
            }
        }
        return {cnt, total};
    } 
};
