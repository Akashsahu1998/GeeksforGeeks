
// Que 05). Remove duplicate elements from sorted Array. 
// Que Link :- https://practice.geeksforgeeks.org/problems/remove-duplicate-elements-from-sorted-array/1

// Implementation

// 1st Approach in CPP
// Time Complexity = O(N), Space Complexity = O(1)

int remove_duplicate(int a[],int n){
    int index = n;
    for(int itr = 0; itr < n-1; itr++){
        if(a[itr] == a[itr+1]){
             a[itr] = 0;
             index--;
        }
    }
    for(int itr = 0, jtr = itr+1; itr < n-1; itr++){
        if(a[itr] == 0){
            if(a[itr] == 0 && a[jtr] == 0){
                jtr++;
                itr--;
            }
            else{
                a[itr] = a[jtr];
                a[jtr] = 0;
                jtr++;
            }
            if(jtr == n) break;
        } 
        else jtr++;
    }
    return index;
}


// 2nd Approach in Java
// Time Complexity = O(N), Space Complexity = O(1)

int remove_duplicate(int a[],int n){
    int index = n;
    for(int itr = 0; itr < n-1; itr++){
        if(a[itr] == a[itr+1]){
             a[itr] = 0;
             index--;
        }
    }
    for(int itr = 0, jtr = itr+1; itr < n-1; itr++){
        if(a[itr] == 0){
            if(a[itr] == 0 && a[jtr] == 0){
                jtr++;
                itr--;
            }
            else{
                a[itr] = a[jtr];
                a[jtr] = 0;
                jtr++;
            }
            if(jtr == n) break;
        } 
        else jtr++;
    }
    return index;
}
