
// Que) 9. Intersection of Two Linked Lists 
// Que Link :- https://practice.geeksforgeeks.org/problems/intersection-of-two-linked-list/1

// Implementation

// Using unrodered_set
// Time Complexity = O(N), Space Complexity = O(N)
class Solution
{
    public:    
    Node* findIntersection(Node* head1, Node* head2){
        unordered_set<int> st;
        
        // Storing the Node data in the set
        Node* cur = head2;        
        while(cur){
            st.insert(cur->data);
            cur = cur->next;
        }
        
        Node* res = new Node(0);
        Node* resCur = res;
        
        // Iteratign & Checking if node is already present into set,
        // it means that is the intersection point.
        cur = head1;
        while(cur){
            if(st.find(cur->data) != st.end()) {
                Node* dummy = new Node(cur->data);
                resCur->next = dummy;
                resCur = resCur->next;
            }
            cur = cur->next;
        }
        
        resCur->next = NULL;
        
        // returnign res->next, bcz res points to 0
        return res->next;
    }
};

