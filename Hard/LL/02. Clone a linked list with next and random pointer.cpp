
// Que) 02. Clone a linked list with next and random pointer
// Que Link :- https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1/?track=amazon-linkedlists&batchId=192#

// Implementation

// Naive Approach
// Using Unordered Map
// Time Complexity = O(N), Space Complexity = O(N)
class Solution
{
    public:
    Node *copyList(Node *head)
    {
        //Write your code here
        if(!head) return NULL;
        
        Node* copy = new Node(0);
        Node* cur = head;
        Node* copyCur = copy;
        
        // buidling the next pointer for copy list &
        // pushing into map with the pair org node and copy node
        unordered_map<Node*, Node*> mp;
        while(cur){
            copyCur->next = new Node(cur->data);
            mp[cur] = copyCur->next;
            cur = cur->next;
            copyCur = copyCur->next;
        }
        
        // again pointing cur to head &
        // copycur to copynext, bcz now we need to build random pointer also
        cur = head;
        copyCur = copy->next;
        
        // buidling the random pointer for copy list
        // from the map key value
        // key = org, value = copy(which we created)
        while(cur){
            if(cur->arb ){
                copyCur->arb  = mp[cur->arb ];
            }
            cur = cur->next;
            copyCur = copyCur->next;
        }        
		// return copy->next, bcz copy was pointing to 0
        return copy->next;
    }
};


// Efficient Approach
// Time Complexity = O(N), Space Complexity = O(1)
class Solution
{
    public:
    Node *copyList(Node *head)
    {
        //Write your code here
        if(!head) return NULL;
        
        // Building the dummyNode after each and every original node(cur)
        // pointing the cur->next to dummyNode & dummyNode to cur->next->next
        Node *cur = head;        
        while(cur){
            Node *front = cur->next;
            Node *dummyNode = new Node(cur->data);
            cur->next = dummyNode;
            dummyNode->next = front;
            cur = front;
        }
        
        // Pointing the randomNode in each and every dummy node we created
        cur = head;
        while(cur){
            if(cur->arb){
                // we are putting random node(cur->random->next) in dummyNode(cur->next->random) only
                cur->next->arb = cur->arb->next;
            }
            cur = cur->next->next;
        }
        
        // Pointing the copy to the first dummy node, so we can return it.
        cur = head;
        Node* copy = new Node(0);
        Node* copyCur = copy;
        
        // deleting the links of org nodes to dummy nodes
        while(cur){            
            copyCur->next = cur->next;
            cur->next = cur->next->next;
            cur = cur->next;
            copyCur = copyCur->next;
        }
		// return copy->next, bcz copy was pointing to 0
        return copy->next;
    }
};
