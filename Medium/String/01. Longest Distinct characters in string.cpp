
// Que 01). Longest Distinct characters in string
// Que Link :- https://practice.geeksforgeeks.org/problems/longest-distinct-characters-in-string5848/1/#


// Implementation

// 1st Approach
// Using window sliding technique
// Using Unordered Map
// Time Complexity = O(N)
// Space Complexity = O(N), it will be having maximum no. of unique element into current window 
int longestSubstrDistinctChars (string s){
    // using map to store the unique char of current window    
    unordered_map<char, int> mp;
    int maxCount = 0, curCount = 0;
    
    // iterating over the string
    // using itr & jtr to track current window in which, we which we are having unique element
    // basically jtr will be having the start index of the current unqiue window, and
    // itr will be having the last index of the current unqiue window
    for(int itr = 0, jtr = 0; itr < s.size(); itr++){
        
        // get the current char
        char ch = s[itr];
        
        // if current char is present into map, then delete all key till that already present char, and decrease the count
        if(mp[ch]){
            while(s[jtr] != ch){
                mp[s[jtr]]--;
                curCount--;
                jtr++;
            }
            
            mp[s[jtr]]--;
            curCount--;
            jtr++;                
        }
        
        // add the current char in last, and incr the count, bcz now that char is going to add into the map
        mp[ch]++;
        curCount++;            
        maxCount = max(maxCount, curCount);
    }
    return maxCount;
}


// 2nd Approach
// Using window sliding technique
// Using Unordered Set
// Time Complexity = O(N)
// Space Complexity = O(N), it will be having maximum no. of unique element into current window
int longestSubstrDistinctChars (string s){
    // using set to store the unique char of current window
    unordered_set<char> st;
    int maxCount = 0;
    
    // iterating over the string
    // using itr & jtr to track current window in which, we which we are having unique element
    // basically jtr will be having the start index of the current unqiue window, and
    // itr will be having the last index of the current unqiue window
    for(int itr = 0, jtr = 0; itr < s.size(); ){
        char ch = s[itr];
        
        // if not present into set, just insert it and store the max result and incr itr
        if(st.find(ch) == st.end()){
            st.insert(ch);
            itr++;
            maxCount = max(maxCount, itr - jtr);
        }
        else{
            // if its already present then remove the jtr index char from set and incr jtr
            st.erase(s[jtr++]);
        }
    }
    return maxCount;
}


// 3rd Approach
// Using window sliding technique
// Using Unordered Map
// Time Complexity = O(N)
// Space Complexity = O(N), it will be having all the unique element present into map
int longestSubstrDistinctChars (string s){
    // using map to store the unique char of and their respective index according to the given string(s)
    unordered_map<char, int> mp;                
    int maxCount = 0;
    
    // iterating over the string
    // using itr & jtr to track current window in which, we which we are having unique element
    // basically jtr will be having the start index of the current unqiue window, and
    // itr will be having the last index of the current unqiue window
    for(int itr = 0, jtr = 0; itr < s.size(); itr++){
        char ch = s[itr];
        
        // if char already presents then update the start of the current unique window(jtr)
        if(mp.find(ch) != mp.end()){
            jtr = max(jtr, mp[ch] + 1); // we are taking max bcz, to handle these type of cases, i.e : s = "abba";
        }
        
        // putting the current index as a value into the key char
        mp[ch] = itr;
        
        // getting the maxCount using the start(jtr) of the current unqiue window and end(itr) of the current unique window + 1
        maxCount = max(maxCount, itr - jtr + 1);
    }
    return maxCount;
}
