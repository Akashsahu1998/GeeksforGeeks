
// Que 01). Stock span problem
// Que Link :- https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1#

// Implementation
// Time Complexity = O(N), Space Complexity = O(N)
class Solution
{
    public:
    //Function to calculate the span of stock’s price for all n days.
    vector <int> calculateSpan(int price[], int n){
       stack<pair<int, int>> s;
       vector <int> res;
       
       for(int itr = 0; itr < n; itr++){
           int span = 1;
            while(!s.empty() && s.top().first <= price[itr]){
                span += s.top().second;
                s.pop();
            }
            s.push({price[itr], span});
            res.push_back(span);
       }
        return res;
    }
};
