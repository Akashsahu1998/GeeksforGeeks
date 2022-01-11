
// Que 01). Generate Binary Numbers
// Que Link :- https://practice.geeksforgeeks.org/problems/generate-binary-numbers-1587115620/1/

// Implementation

// Time Complexity = O(NLogN), Space Complexity = O(NLogN)
vector<string> generate(int n){
	vector<string> res;
	
	for(int itr = 1; itr <= n; itr++){
	    string str = "";
	    int num = itr;
	    while(num){
	        str = to_string(num % 2) + str;
	        num /= 2;
	    }
	    res.push_back(str);
	}
	
	return res;
}
