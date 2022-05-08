
// Que 01). N meetings in one room
// Que Link :- https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1#

// Implementation

// Using Sorting
// Time Complexity = O(NLogN)
// Space Complexity = O(N)

class Solution{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n){
        vector<pair<int, int>> meetings;
        
        // O(N)
        for(int i = 0; i < n; i++){
            meetings.push_back({end[i], start[i]});
        }
        
        // O(NlogN)
        sort(meetings.begin(), meetings.end());
        
        // O(N)
        int endLimit = meetings[0].first, cnt = 1;
        for(int i = 1; i < n; i++){
            if(endLimit < meetings[i].second){
                endLimit = meetings[i].first;
                cnt++;
            }
        }
        
        return cnt;
    }
};

