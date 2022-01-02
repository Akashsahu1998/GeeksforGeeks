
// Que) 03. Queue Reversal
// Que Link :- https://practice.geeksforgeeks.org/problems/queue-reversal/1

// Implementation

// Time Complexity : O(N), Space Complexity : O(N)
// Using recursion
void reverse(queue<int> &q){
    if(q.empty()) return;
    int val = q.front();
    q.pop();
    reverse(q);
    q.push(val);
}

queue<int> rev(queue<int> q){
    reverse(q);
    return q;
}


// Time Complexity : O(N), Space Complexity : O(N)
// Using Iterative approach

queue<int> rev(queue<int> q){
    stack<int> st;
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }
    
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    return q;
}
