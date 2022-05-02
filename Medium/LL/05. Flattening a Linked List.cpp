
// Que) 05. Flattening a Linked List 
// Que Link :- https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

// Implementation


// Using Merge Sort
// 1st Approach
// Time Complexity = O(N)
// Space Complexity = O(1)

// merge two list
Node* merge(Node* l1, Node* l2){
    Node* res = new Node(0);
    Node* temp = res;
    
    while(l1 && l2){
        if(l1->data < l2->data){
            temp->bottom = new Node(l1->data);
            l1 = l1->bottom;
        }
        else{
            temp->bottom = new Node(l2->data);
            l2 = l2->bottom;
        }
        
        temp = temp->bottom;
    }
    
    if(l1) temp->bottom = l1;
    if(l2) temp->bottom = l2;
    
    return res->bottom;
}

Node* flatten(Node *root){
  if(!root || !root->next) return root;
  
  root->next = flatten(root->next);
  
  root = merge(root, root->next);
  return root;
}
