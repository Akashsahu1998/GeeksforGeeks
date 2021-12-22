
// Que) 8. Add 1 to a number represented as linked list 
// Que Link :- https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

// Implementation

// Time Complexity = O(N), Space Complexity = O(1)
class Solution
{
    public:
    Node* reverseList(Node *head){
        if(!head) return NULL;
        Node* prev = NULL;
        while(head->next){
            Node* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        head->next = prev;
        return head;
    }
    
    Node* addOne(Node *head) {
        
        // reversing the list to point to the last node, bcz we need to add 1 at last
        head = reverseList(head);
        Node *cur = head;
        
        // we have to add 1 in the last element that's why initialize carry as 1;
        int carry = 1;
        while(cur){
            int sum = cur->data + carry;
            carry = sum > 9 ? 1 : 0;
            cur->data = sum > 9 ? 0 : sum;
            if(!cur->next) break;
            cur = cur->next;
        }
        
        // if carry is 1 it means, we have to create one more node
        // i.e = 99 + 1 = 100 for this we got extra digit as 0
        if(carry){
            Node* newNode = new Node(carry);
            cur->next = newNode;
        }
        
        // again reversing the list
        // passing the head bcz, head was pointing to the last element,
        // we need to reverse from last
        head = reverseList(head);
        
        return head;
    }
};

