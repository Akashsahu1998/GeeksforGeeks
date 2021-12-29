
// Question) 04. Sort a stack
// Link = https://practice.geeksforgeeks.org/problems/sort-a-stack/1

// Implementation

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
