
// Que) 01. Implement stack using array
// Que Link :- https://practice.geeksforgeeks.org/problems/implement-stack-using-array/1

// Implementation

// Time Complexity : (O(1), Space Complexity : O(1)
//Function to push an integer into the stack.
void MyStack :: push(int x){
    arr[++top] = x;
}

//Function to remove an item from top of the stack.
int MyStack :: pop(){
    return top == -1 ? -1 : arr[top--];
}
