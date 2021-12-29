
// Question) 04. Sort a stack
// Link = https://practice.geeksforgeeks.org/problems/sort-a-stack/1

// Implementation

// 1st Approach
// Using Multiset
// Time Complexity = O(NLogN), Space Complexity = O(N)
void SortedStack :: sort(){
   multiset<int> st;
   while(!s.empty()){
       st.insert(s.top());
       s.pop();
   }
   
   for(auto itr : st){
       s.push(itr);
   }
}


// 2nd Approach
// Using Recursion
// for every n element we are traversing n element
// i.e => [3, 2, 1]
// Time Complexity = O(N^2), Space Complexity = O(N) 
void insertAndSort(stack<int> &s, int temp){
    // basecase
    if(s.empty() || s.top() < temp){
        s.push(temp);
    }
    else{
        int lastElement = s.top();
        s.pop();
        insertAndSort(s, temp);
        s.push(lastElement);
    }
}

void SortedStack :: sort(){
   // basecase
   if(s.empty()) return;
   
   int temp = s.top();
   s.pop();
   
   sort();
   insertAndSort(s, temp);
}
