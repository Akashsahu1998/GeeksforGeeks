
// Que) 7. Given a linked list of 0s, 1s and 2s, sort it. 
// Que Link :- https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

// Implementation

// Time Complexity = O(N), Space Complexity = O(1)
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Creating the pointer for their respective values
		Node *cur = head;
        Node *ptrZero = NULL, *ptrZeroHead = NULL;
        Node *ptrOne = NULL, *ptrOneHead = NULL;
        Node *ptrTwo = NULL, *ptrTwoHead = NULL;
        
        // moving cur and pushing 0, 1 & 2 into their respective pointer according to there values
        while(cur){
            if(cur->data == 0){
                if(!ptrZero){
                    ptrZero = cur;
                    ptrZeroHead = ptrZero;
                }
                else {
                    ptrZero->next = cur;
                    ptrZero = ptrZero->next;
                }
            }
            else if(cur->data == 1){
                if(!ptrOne){
                    ptrOne = cur;
                    ptrOneHead = ptrOne;
                }
                else {
                    ptrOne->next = cur;
                    ptrOne = ptrOne->next;
                }
            }
            else if(cur->data == 2){
                if(!ptrTwo){
                    ptrTwo = cur;
                    ptrTwoHead = ptrTwo;
                }
                else {
                    ptrTwo->next = cur;
                    ptrTwo = ptrTwo->next;
                }
            }
            cur = cur->next;
        }
        
        Node *returnNode = NULL;
        
		// if 0 is present then 0 will be our head
		if(ptrZero){
            returnNode = ptrZeroHead;
        }
                
        if(ptrOne){
        	// if 0 is not present then 1 will be our head
            if(!returnNode) returnNode = ptrOneHead;
            
            // if zero is present then 0th next will be our 1's head
            if(ptrZero) ptrZero->next = ptrOneHead;
        }
                
        if(ptrTwo){
        	// if 0 and 1 is not present then 2 will be our head
            if(!returnNode) returnNode = ptrTwoHead;
            
            // if both 0 and 1 are there then 1's next will be out 2's head
            if(ptrZero && ptrOne){
                ptrOne->next = ptrTwoHead;
            } // if both 0 is not present and one is present then 1's next will be out 2's head
            else if(!ptrZero && ptrOne){
                ptrOne->next = ptrTwoHead;
            } // if both 0 is present and 1 is not present then 0th next will be our 2's head
            else if(ptrZero){
                ptrZero->next = ptrTwoHead;
            }
        }
        
        // infinite loop cases
        // if 2 is present then we need to add the null at the last of 2, bcz 2 is the last node
        if(ptrTwo){
            ptrTwo->next = NULL;
        } // if 2 is not present and 1 is present then we need to add the null at the last of 1, bcz 1 will be out last node
        else if(ptrOne){
            ptrOne->next = NULL;
        }
        // for 0 we will not add any null bcz, obivisouly if 1 & 2 are not there then it means, 0 is not there
        // so there is not chance of infinite loop
        
        return returnNode;
    }
};

