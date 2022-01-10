
// Que 01). Stock buy and sell
// Que Link :- https://practice.geeksforgeeks.org/problems/stock-buy-and-sell-1587115621/1

// Implementation

// Time Complexity = O(N), Space Complexity = O(N)
class Solution{
public:
    //Function to find the days of buying and selling stock for max profit.
    vector<vector<int> > stockBuySell(vector<int> arr, int n){
        vector<vector<int> > res;
        
        stack<int> st;
        st.push(0);
        
        for(int itr = 1; itr < n; itr++){
            if(arr[st.top()] < arr[itr]){
                st.push(itr);
            }
            else if(st.size() > 1){
                int lastIndex = st.top();
                while(st.size() > 1){
                    st.pop();
                }
                int firstIndex = st.top();
                st.pop();
                res.push_back({firstIndex, lastIndex});
                st.push(itr);
            }
            else{
                while(!st.empty()) st.pop();
                st.push(itr);
            }
        }
        
        if(!st.empty() && st.size() > 1){
            int lastIndex = st.top();
            while(st.size() > 1){
                st.pop();
            }
            int firstIndex = st.top();
            st.pop();
            res.push_back({firstIndex, lastIndex});
        }
        return res;
    }
};
