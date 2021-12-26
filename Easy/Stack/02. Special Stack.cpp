
// Question) 02.  Special Stack
// Link = https://practice.geeksforgeeks.org/problems/special-stack/1

// Implementation

// Time Complexity = O(1), Space Complexity = O(N)
void push(stack<int>& s, int a){
	int minValue;
	if(s.size() == 0) {
	    s.push(a);
	    s.push(a);
	}
	else {
	    minValue = s.top();
	    minValue = min(minValue, a);
	    s.push(a);
	    s.push(minValue);
	}
}

bool isFull(stack<int>& s,int n){
	if(s.size()/2 == n) return true;
	return false;
}

bool isEmpty(stack<int>& s){
	if(s.size()/2) return false;
	return true;
}

int pop(stack<int>& s){
	s.pop();
	int res = s.top();
	s.pop();
	return res;
}

int getMin(stack<int>& s){
	return s.top();
}
