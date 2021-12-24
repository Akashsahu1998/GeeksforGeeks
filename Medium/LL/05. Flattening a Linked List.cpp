
// Que) 05. Flattening a Linked List 
// Que Link :- https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

// Implementation

// Time Complexity = O(N), Space Complexity = O(1)
Node *flatten(Node *root){
   vector<int> vec;
   Node *cur = root;
   while(cur){
       vec.push_back(cur->data);
       if(cur->bottom){
           // storing the cur->next
           Node *bottomNode = cur->bottom, *storedNode = cur;
           
           // iterating over the bottom of the cur, till the end, and
           // adding into set
           while(bottomNode->bottom){
               vec.push_back(bottomNode->data);
               bottomNode = bottomNode->bottom;
           }
           vec.push_back(bottomNode->data);
           cur = storedNode;
       }
       cur = cur->next;
   }
   
   // sorting the vector to maintain the non decreasing order
   sort(vec.begin(), vec.end());
   
   // creating a new dummy list
   Node *flatteningNode = new Node(0);
   Node *res = flatteningNode;
   for(auto a : vec){ 
       Node *newNode = new Node(a);
       flatteningNode->bottom = newNode;
       flatteningNode = flatteningNode->bottom;
   }
   return res->bottom;
}
