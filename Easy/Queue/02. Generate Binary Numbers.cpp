
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


// https://www.geeksforgeeks.org/interesting-method-generate-binary-numbers-1-n/
// Efficient Approach
// Using Queue
// Time Complexity = O(N), Space Complexity = O(NLogN)
vector<string> generate(int n){
	vector<string> res;
	queue<string> q;
	q.push("1");
	
	while(n--){
	    string str1 = q.front();
	    q.pop();
	    res.push_back(str1);
	    
	    // Store str1 before changing it
	    string str2 = str1;
	    
	    // apppend "0" to str1 & "1" to str2, and simultaneously push into q
	    q.push(str1.append("0"));
	    q.push(str2.append("1"));
	}
	
	return res;
}
