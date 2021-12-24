
// Que) 12. Check if Linked List is Palindrome
// Que Link :- https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

// Implementation

// Using slow & fast ptr
// Time Complexity = O(N), Space Complexity = O(1)
class Solution{
  public:
    Node* reverse(Node *dummy){
        if(!dummy) return NULL;
        Node* prev = NULL;
        while(dummy->next){
            Node *temp = dummy->next;
            dummy->next = prev;
            prev = dummy;
            dummy = temp;
        }
        dummy->next = prev;
        return dummy;
    }
  
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head){
        Node *slow = head, *fast = head;
        
        // slow will reach to mid
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        // reversing all nodes after the mid node
        slow->next = reverse(slow->next);
        
        // again starting
        Node* start = head;
        slow = slow->next;
        
        // trying to match the data from start and after the mid(reversed list)
        while(slow){
            if(slow->data != start->data) return false;
            slow = slow->next;
            start = start->next;
        }
        return true;
    }
};

