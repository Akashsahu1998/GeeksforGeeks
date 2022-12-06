
// Que 09).  Count distinct pairs with difference k
// Que Link :- https://practice.geeksforgeeks.org/problems/count-distinct-pairs-with-difference-k1233/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// Implementation

// Using unordered_map
// Time Complexity : O(N)
// Space Complexity : O(N)
class Solution{
	public:
	int TotalPairs(vector<int>nums, int k){
	    
	    unordered_map<int, int> mp;
	    int cnt = 0;
	    
	    // add the frequency of elements into map
	    for(auto num : nums){
	        mp[num]++;
	    }
	    
	    // iterate over map
	    for(auto itr : mp){
	        
	        // check differently for zero and non zero value of k
	        if(k != 0 && mp.find(itr.first - k) != mp.end()){
	            cnt++;
	        }
	        
	        // if k is 0 then check this condition, bcz if any number is appearing more than
	        // once than it means that number can make 0 after subtracting bcz numbers will 
	        // be same, so thats why to avoid duplicates paris we are taking into count once
	        // with the help of map
	        if(k == 0 && itr.second > 1) cnt++;
	    }
	    
	    return cnt;
	}
};
