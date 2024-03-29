
// Que 02). Reverse First K elements of Queue 
// Que Link :- https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1

// Implementation

//Function to push an element in queue by using 2 stacks.
// two time traversal
// using vector
// // Time Complexity = O((N)+O(N)) = O(N), Space Complexity = O(N)
queue<int> modifyQueue(queue<int> q, int k) {
    vector<int> vec;
    
    while(!q.empty()){
        vec.push_back(q.front());
        q.pop();
    }
    
    for(int itr = k-1; itr >= 0; itr--){
        q.push(vec[itr]);
    }
    
    for(int itr = k; itr < vec.size(); itr++){
        q.push(vec[itr]);
    }
    
    return q;
}


// 1 time + k times traversal
// using stack
// // Time Complexity = O((N)+O(K)) = O(N), Space Complexity = O(N)
queue<int> modifyQueue(queue<int> q, int k) {
    stack<int> st;
    
    for(int itr = 0; itr < k; itr++){
        st.push(q.front());
        q.pop();
    }
    
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    
    for(int itr = 0; itr < q.size() - k; itr++){
        q.push(q.front());
        q.pop();
    }
    
    return q;
}
