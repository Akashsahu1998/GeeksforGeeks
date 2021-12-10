
// Que 01). Add two numbers represented by linked lists.
// Que Link :- https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1#

// Implementation
// Time Complexity = O(max(l1, l2)), Space Complexity = O(1)

class Solution
{
    public:
    struct Node* reverse(struct Node* head){
        Node *nex = NULL, *prev = NULL;
        while(head){
            nex = head->next;
            head->next = prev;
            prev = head;
            head = nex;
        }
        return prev;
    }
    
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first = reverse(first);
        second = reverse(second);
        Node *res = NULL, *cur = NULL;
        int carry = 0;
        while(first || second){
            int sum = (first ? first->data : 0) + (second ? second->data : 0) + carry;
            carry = (sum > 9) ? 1 : 0;
            sum = sum % 10;
            Node *temp = new Node(sum);
            if(res == NULL) res = temp;
            else cur->next = temp;
            cur = temp;
            if(first) first = first->next;
            if(second) second = second->next;
        }
        
        if(carry){
            Node *temp = new Node(carry);
            cur->next = temp;
            cur = temp;
        }
        res = reverse(res);
        return res;
    }
};
