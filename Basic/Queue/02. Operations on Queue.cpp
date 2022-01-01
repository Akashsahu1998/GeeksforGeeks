
// Que) 01. Queue Operations
// Que Link :- https://practice.geeksforgeeks.org/problems/queue-operations/1

// Implementation

// Time Complexity : O(1) for enqueue(), dequeue() & front(), O(N) for find()
// Space Complexity : O(1) for all
class Solution{
    public:
    
    //Function to push an element in queue.
    void enqueue(queue<int> &q,int x){
       q.push(x);
    }
     
    //Function to remove front element from queue.
    void dequeue(queue<int> &q){
        q.pop();
    }
    
    //Function to find the front element of queue.
    int front(queue<int> &q){
        return q.front();
    }
    
    //Function to find an element in the queue.
    string find(queue<int> q, int x){
        int size = q.size();
        string res = "No";
        while(size--){
            if(q.front() == x) res = "Yes";
            q.push(q.front());
            q.pop();
        }
        return res;
    }
};
