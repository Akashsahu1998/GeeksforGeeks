
// Que) 01. Implement Atoi
// Que Link :- https://practice.geeksforgeeks.org/problems/implement-atoi/1#

// Implementation

// Time Complexity = O(N)
// Space Complexity = O(1)
class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        int itr = 0, num = 0, sign = 1;
        if(str[itr] == '+' || str[itr] == '-'){
            sign = str[itr++] == '+' ? 1 : -1;
        }
        while(itr < str.size() && str[itr] >= '0' && str[itr] <= '9'){
            num = num * 10 + str[itr++] - '0';
        }
        if(itr != str.size()) return -1;
        return num * sign;
    }
};
