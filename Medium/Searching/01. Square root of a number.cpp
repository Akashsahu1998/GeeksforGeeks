
// Que 01). Square root of a number
// Que Link :- https://practice.geeksforgeeks.org/problems/square-root/1

// Implementation

// 1st Approach
// Using Sqrt function
// Time Complexity = O(LogN)
// Space Complexity = O(1)
long long int floorSqrt(long long int x) {
    return sqrt(x);
}


// 2nd Approach
// Time Complexity = O(sqrt(n))
// Space Complexity = O(1)
long long int floorSqrt(long long int x) {
    long long int res = -1;
    for(long long int itr = 1; itr <= x; itr++){
        long long int val = itr*itr;
        if(val == x){
            res = itr;
            break;
        }
        else if(val > x){
            res = itr-1;
            break;
        }
    }
    return res;
}
