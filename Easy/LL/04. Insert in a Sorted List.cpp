
// Que 03). Insert in a Sorted List 
// Que Link :- https://practice.geeksforgeeks.org/problems/insert-in-a-sorted-list/1

// Implementation

// Time Complexity = O(N), Space Complexity = O(1)
class Solution{
  public:
    Node *sortedInsert(struct Node* head, int data) {
        struct Node *newNode = new Node(data);
        if(head->data >= data){
            newNode->next = head;
            return newNode;
        }
        Node* cur = head;
        while(cur->next && cur->next->data < data){
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        return head;
    }
};

