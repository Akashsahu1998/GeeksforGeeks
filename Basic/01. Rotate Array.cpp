
// Que 01). Rotate Array. 
// Que Link :- https://cutt.ly/uhS9bkD

// Implementation
// Time Complexity = O(N), Space Complexity = O(N)

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	
	while(tc--){
	    int size, d;
	    cin >> size >> d;
	    int arr[size];
	    vector<int> vect;
	    for(int itr = 0; itr < size; itr++){
	        cin >> arr[itr];
	    }
	    
	    for(int itr = d; itr < size; itr++){
	        vect.emplace_back(arr[itr]);
	    }
	    
	    for(int itr = 0; itr < d ; itr++){
	        vect.emplace_back(arr[itr]);
	    }
	    
	    // Printing
	    for(int itr = 0; itr < size; itr++){
	        cout << vect[itr] << " ";
	    }
	    cout << endl;
	}	
	
	return 0;
}
