
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
