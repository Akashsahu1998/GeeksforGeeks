
// Que 01). Queue using two Stacks
// Que Link :- https://practice.geeksforgeeks.org/problems/queue-using-two-stacks/1

// Implementation

// Time Complexity = O(N), Space Complexity = O(N)

//Function to push an element in queue by using 2 stacks.
void StackQueue :: push(int x){
    s1.push(x);
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop(){
    int res = -1;
    
    while(!s1.empty()){
        res = s1.top();
        if(s1.size() != 1) s2.push(s1.top());
        s1.pop();
    }
    
    while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }
    
    return res;
}
