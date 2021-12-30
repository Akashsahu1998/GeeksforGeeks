
// Que) 02. Implement Stack using Linked List 
// Que Link :- https://practice.geeksforgeeks.org/problems/implement-stack-using-linked-list/1

// Implementation

// Time Complexity : (O(1), Space Complexity : O(1)
//Function to push an integer into the stack.
void MyStack ::push(int x) 
{
    struct StackNode *temp = new StackNode(x);
    temp->next = top;
    top = temp;
}

//Function to remove an item from top of the stack.
int MyStack ::pop() 
{
    if(!top) return -1;
    
    StackNode *temp = top;
    top = top->next;
    int returnValue = temp->data;
    delete temp;
    return returnValue;
}
