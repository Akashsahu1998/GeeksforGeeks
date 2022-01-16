
// Que 03). Match specific pattern
// Que Link :- https://practice.geeksforgeeks.org/problems/match-specific-pattern/1

// Implementation

// 1st Approach
// Using unoredered_map
// Time Complexity = O(N*K), Space Complexity = O(N)

// function to create a new hashcode of a word
string createHash(string str){
    // mp to create a new hash code a particular word
    unordered_map<char, int> mp;
    
    string hashCode = "";
    for(int itr = 0, val = 1; itr < str.size(); itr++){
        if(mp[str[itr]] == 0){
            mp[str[itr]] = val++;
        }
        hashCode += mp[str[itr]];
    }
    return hashCode;
}

vector<string> findMatchedWords(vector<string> dict,string pattern){
    vector<string> res;
    
    // making a new hash code for pattern
    string patternHashCode = createHash(pattern);
    
    // making a new hash code for all the words which are in dict
    for(int itr = 0; itr < dict.size(); itr++){
        if(createHash(dict[itr]) == patternHashCode)
            res.push_back(dict[itr]);
    }
    
    return res;
}



// 2nd Approach
// Using unoredered_map
// Time Complexity = O(N*K), Space Complexity = O(N)

vector<string> findMatchedWords(vector<string> dict,string pattern){
    vector<string> res;
    
    // making a new hash code for all the words which are in dict
    for(int itr = 0; itr < dict.size(); itr++){
        
        string str = dict[itr];
        if(str.size() != pattern.size()) continue;
        
        unordered_map<char, int> mp;
        int jtr = 0;
        
        // mapping the currentindex char of pattern to the currentindex char of str
        for(; jtr < pattern.size(); jtr++)    {
            
            // if currentindex char of pattern present into map
            if(mp[pattern[jtr]]){
                
                // if its present and its value is not equal to currentindex char of str then break, it means they are not matching pattern
                if(mp[pattern[jtr]] != str[jtr]) break;
            }
            else{   // if currentindex char of pattern not present into map
                mp[pattern[jtr]] = str[jtr];
            }
        }
        
        // if jtr == pattern.size() it means, it reaches till last index, so there are all char matching to pattern char.
        if(jtr == pattern.size()) res.push_back(str);
    }
    
    return res;
}

