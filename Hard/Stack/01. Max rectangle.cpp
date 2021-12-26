
// Que) 01. Max rectangle
// Que Link :- https://practice.geeksforgeeks.org/problems/max-rectangle/1

// Implementation

// Efficient Approach
// Time Complexity = O(Row Col) + O(Col) = O(Row*Col)
// Space Complexity = O(Col)
class Solution{
  public:
    int findTheLargestRectangeInHistogram(vector<int> heights){
        int n = heights.size();
        vector<int> leftArr(n), rightArr(n);
        stack<int> st;

        // finding element on left which is lesser than the current element
        for(int itr = 0; itr < n; itr++){
            while(!st.empty() && heights[st.top()] >= heights[itr]){
                st.pop();
            }

            // if stack is empty then put 0
            if(st.empty()){
                leftArr[itr] = 0;
            }
            else{
                leftArr[itr] = st.top() + 1;
            }

            st.push(itr);
        }

        // clear stack, to create rightArr
        while(!st.empty()){
            st.pop();
        }

        // finding element on right which is lesser than the current element
        for(int itr = n-1; itr >= 0; itr--){
            while(!st.empty() && heights[st.top()] >= heights[itr]){
                st.pop();
            }

            // if stack is empty then put n-1
            if(st.empty()){
                rightArr[itr] = n-1;
            }
            else{
                rightArr[itr] = st.top() - 1;
            }

            st.push(itr);
        }

        // calculating the max rectangle by using left & right less current value
        int ans = -1;
        for(int itr = 0; itr < n; itr++){
            int sum = (rightArr[itr] - leftArr[itr] + 1) * heights[itr];
            ans = max(ans, sum);
        }

        return ans;
    }
  
    int maxArea(int matrix[MAX][MAX], int n, int m) {
        int ans = 0;
        vector<int> rowArr(m);
        for(int itr = 0; itr < n; itr++){            
            for(int jtr = 0; jtr < m; jtr++){
                if(itr == 0) rowArr[jtr] = matrix[itr][jtr];
                else {  // if value is 1 then add it with the value of rowArr otherwise simple put 0
                    if(matrix[itr][jtr] == 1) rowArr[jtr] += matrix[itr][jtr];
                    else rowArr[jtr] = 0;
                }
            }
            ans = max(ans, findTheLargestRectangeInHistogram(rowArr));
        }
        
        // using the rectangle in histogram solution
        return ans;
    }
};
