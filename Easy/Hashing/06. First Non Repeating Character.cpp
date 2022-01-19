
// Que 06). First Non Repeating Character 
// Que Link :- https://practice.geeksforgeeks.org/problems/non-repeating-character-1587115620/1

// Implementation

// Using unoredered_map
// Time Complexity = O(N), Space Complexity = O(N)
string find(string str) {
    unordered_map<char, int> mp;
    
    for(auto ch : str){
        mp[ch]++;
    }
    
    string res = "";
    
    for(auto ch : str){
        if(mp[ch] == 1) return res += ch;
    }
    
    return "-1";
}
