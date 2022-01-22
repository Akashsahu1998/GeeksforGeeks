
// Que 02). Majority Element
// Que Link :- https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1

// Implementation

// Using Moore's Voting Algorithm
// Time Complexity = O(N),
// Space Complexity = O(1)
int majorityElement(int arr[], int size){
        
    int count = 0, majorityElement = 0;
    for(int itr = 0; itr < size; itr++){
        if(count == 0) majorityElement = arr[itr];
        
        if(majorityElement == arr[itr]) count++;
        else count -= 1;
    }
    
    // checking if that majority element is present more than size/2 times of not
    count = 0;
    for(int itr = 0; itr < size; itr++){
        if(arr[itr] == majorityElement) count++;
    }
    
    return (count > size/2) ? majorityElement : -1;
}
