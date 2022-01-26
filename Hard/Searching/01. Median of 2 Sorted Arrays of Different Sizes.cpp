
// Que) 01. Median of 2 Sorted Arrays of Different Sizes
// Que Link :- https://practice.geeksforgeeks.org/problems/median-of-2-sorted-arrays-of-different-sizes/0/?category%5B%5D=Searching&page=2&query=category%5B%5DSearchingpage2

// Implementation

// Using Binary Search
// Time Complexity : O(log(min(n1, n2)))
// Space Complexity : O(1)
class Solution{
    public:
    double MedianOfArrays(vector<int>& arr1, vector<int>& arr2){
        int n1 = arr1.size(), n2 = arr2.size();
        
        // we want to do binary search on minimum size array
        if(n2 < n1) MedianOfArrays(arr2, arr1);
        
        int low = 0, high = n1;
        
        while(low <= high){
            int cut1 = (low + high) / 2;
            // +1 bcz, if its even suppose n1 = 4, n2 = 6 then cut2 will be 5 
            // and if its odd suppose, n1 = 3, n2 = 4 then cut2 will be 4, bcz we need +1 of mid, that's why
            int cut2 = ((n1 + n2 + 1) / 2) - cut1;
            
            int left1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1];
            int left2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1];
            int right1 = (cut1 == n1) ? INT_MAX : arr1[cut1];
            int right2 = (cut2 == n2) ? INT_MAX : arr2[cut2];
            
            if(left1 <= right2 && left2 <= right1){
                if((n1 + n2) % 2 == 0) return (max(left1, left2) + min(right1, right2)) / 2.0;
                else return max(left1, left2);
            }
            else if(left1 > right2){
                high = cut1 - 1;
            }
            else{
                low = cut1 + 1;
            }
        }
        return 0.0;
    }
};
