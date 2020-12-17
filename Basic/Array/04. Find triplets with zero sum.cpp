
// Que 04). Find triplets with zero sum.
// Que Link :- https://practice.geeksforgeeks.org/problems/find-triplets-with-zero-sum/1

// Implementation

// 1st Approach in CPP
// Time Complexity = O(N^2), Space Complexity = O(1)

bool findTriplets(int arr[], int n)
{ 
    bool ans = false;
    sort(arr, arr + n);
    for(int loop = 0; loop < n-2; loop++){
        int itr = loop + 1, jtr = n - 1;
        while(itr < jtr){
            if((arr[loop] + arr[itr] + arr[jtr]) == 0) return true;
            else if((arr[loop] + arr[itr] + arr[jtr]) < 0) itr++;
            else jtr--;
        }
    }
    return false;
}


// 2nd Approach in Java
// Time Complexity = O(N^2), Space Complexity = O(1)

public boolean findTriplets(int arr[] , int n)
{
    boolean ans = false;
    Arrays.sort(arr);
    for(int loop = 0; loop < n-2; loop++){
        int itr = loop + 1, jtr = n - 1;
        while(itr < jtr){
            if((arr[loop] + arr[itr] + arr[jtr]) == 0) return true;
            else if((arr[loop] + arr[itr] + arr[jtr]) < 0) itr++;
            else jtr--;
        }
    }
    return false;
}
