
// Que 04). Get minimum element from stack
// Que Link :- https://practice.geeksforgeeks.org/problems/get-minimum-element-from-stack/1

// Implementation

// Time Complexity = O(1), Space Complexity = O(1)
class Solution{
    int minEle = INT_MAX;
    stack<int> s;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           if(s.empty()) return -1;
           return minEle;
       }
       
       /*returns poped element from stack*/
       int pop(){
           if(s.empty()) return -1;
           int returnValue = s.top();
           if(s.top() == minEle){
               s.pop();
               minEle = s.top(); 
           }
           s.pop();
           return returnValue;
       }
       
       /*push element x into the stack*/
       void push(int x){
           if(x <= minEle){
               s.push(minEle);
               minEle = x;
           }
           s.push(x);
       }
};
