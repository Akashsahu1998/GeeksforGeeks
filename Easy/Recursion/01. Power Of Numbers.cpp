
// Que 01). Power Of Numbers 
// Que Link :- https://practice.geeksforgeeks.org/problems/power-of-numbers-1587115620/1#

// Implementation

// Using recursion
// Time Complexity = O(LogN)
// Space Complexity = O(LogN), bcz of the recursion call stack
// find the power of numbers in efficient way
// using this way bcz of overflow issue
// in this approach, everytime we are doing modulo, so it will never overflow
// in pow directly we can't do modulo
// it will give the result into O(logN)
class Solution{
    public:
    //You need to complete this fucntion
    long long power(int n, int r){
       if(r == 0) return 1;
       if(r == 1) return n % 1000000007;
       
       long long ans = 1;
       long long temp = power(n, r/2) % 1000000007;
       
       // if r is odd
       // suppose n^5 => n^2 * n^2 * n
       if(r % 2){
           ans = (ans * n) % 1000000007;
       }
       
       // if r is even
       // suppose n^4 => n^2 * n^2
       
       return (ans * ((temp * temp) % 1000000007)) % 1000000007;
    }
};
