
// Que 03). Container With Most Water 
// Que Link :- https://practice.geeksforgeeks.org/problems/container-with-most-water0535/0/?category[]=Mathematical&difficulty[]=1&page=1&query=category[]Mathematicaldifficulty[]1page1#

// Implementation

// Efficient Approach
// Using Two Pointer's Approach
// Time Complexity: O(N)
// Space Complexity: O(1)
long long maxArea(long long A[], int len){
   long long maxAns = 0, start = 0, end = len-1;
   
   while(start < end) {
       maxAns = max((long long)maxAns, min((long long)A[start], A[end]) * (end - start));
       if(A[start] < A[end])
           start++;
       else
           end--;
   }
   return maxAns;
}
