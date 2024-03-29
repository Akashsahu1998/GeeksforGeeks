
// Que) 01. Implement Queue using array
// Que Link :- https://practice.geeksforgeeks.org/problems/implement-queue-using-array/1

// Implementation

// Time Complexity : (O(1), Space Complexity : O(1)

//Function to push an element x in a queue.
void MyQueue :: push(int x){
    arr[rear++] = x;
}

//Function to pop an element from queue and return that element.
int MyQueue :: pop(){
    if(front == rear) return -1;
    return arr[front++];
}
