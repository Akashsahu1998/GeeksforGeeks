
// Question) 01.  Stack using two queues
// Link = https://practice.geeksforgeeks.org/problems/stack-using-two-queues/1

// Implementation

// Time Complexity = O(N), Space Complexity = O(N)

//Function to push an element into stack using two queues.
void QueueStack :: push(int x){
        q1.push(x);
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop(){
    int size = q1.size();
    if(!size) return -1;
    int returnValue = q1.back();
    int itr = 0;
    while(itr++ < size-1){
        q1.push(q1.front());
        q1.pop();
    }
    q1.pop();
    return returnValue;
}
