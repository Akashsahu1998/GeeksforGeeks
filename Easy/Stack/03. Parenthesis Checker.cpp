
// Question) 03. parenthesis checker
// Link = https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1

// Implementation

// Using Stack
// Time Complexity = O(N), Space Complexity = O(N)
class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string str){
        stack<char> s;
        int itr = 0;
        
        while(itr < str.size()){
            if(s.empty()){
                s.push(str[itr]);
            }
            else{
                if(str[itr] == '}' && s.top() == '{') s.pop();
                else if(str[itr] == ']' && s.top() == '[') s.pop();
                else if(str[itr] == ')' && s.top() == '(') s.pop();
                else s.push(str[itr]);
            }
            itr++;
        }
        
        if(s.empty()) return true;
        return false;
    }

};
