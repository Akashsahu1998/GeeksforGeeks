
// Que 01). Find duplicates in an array.
// Que Link :- https://practice.geeksforgeeks.org/problems/find-duplicates-in-an-array/1#

// Implementation
// Time Complexity = O(N), Space Complexity = O(N)

vector<int> duplicates(int arr[], int n) {
    vector<int> vect;
    for(int index, itr = 0; itr < n; itr++){
        arr[arr[itr] % n] += n;
    }
    
    for(int index, itr = 0; itr < n; itr++){
        if(arr[itr] >= n * 2) vect.emplace_back(itr);
    }
    
    if(vect.size() == 0) vect.emplace_back(-1);
        
	return vect;
}
