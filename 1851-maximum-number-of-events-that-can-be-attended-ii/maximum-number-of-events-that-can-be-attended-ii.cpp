// class Solution {
// public:
//     int n;
//     int solve(int i, int lastUsedIdx, vector<vector<int>>& events, int k, vector<vector<int>>&dp){
//         if(i >= n || k==0){
//             return 0;
//         }

//         if(dp[i][k] != -1){
//             return dp[i][k];
//         }

//         // take
//         int take = 0;
//         if(i == 0 || lastUsedIdx == -1 || events[i][0] > events[lastUsedIdx][1]){
//             take = events[i][2] + solve(i+1, i, events, k-1, dp);
//         }

//         // skip
//         int skip = solve(i+1, lastUsedIdx, events, k, dp);
//         int maxi = max(take, skip);
//         return dp[i][k] =  maxi;
//     }
//     int maxValue(vector<vector<int>>& events, int k) {
//         n = events.size();
//         sort(events.begin(), events.end());
//         int lastUsedIdx = -1;
//         vector<vector<int>>dp(n+1, vector<int>(k+1, -1));
//         return solve(0, lastUsedIdx, events, k, dp);
//     }
// };



class Solution {
public:
    int n;

    // Find the index of the next event whose start > current event's end
    int findNext(int i, vector<vector<int>>& events) {
        int lo = i + 1, hi = n - 1;
        int ans = n;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (events[mid][0] > events[i][1]) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }

    int solve(int i, int k, vector<vector<int>>& events, vector<vector<int>>& dp) {
        if (i >= n || k == 0) return 0;
        if (dp[i][k] != -1) return dp[i][k];

        // Option 1: Skip current event
        int skip = solve(i + 1, k, events, dp);

        // Option 2: Take current event
        int nextIndex = findNext(i, events);
        int take = events[i][2] + solve(nextIndex, k - 1, events, dp);

        return dp[i][k] = max(skip, take);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        n = events.size();
        sort(events.begin(), events.end());  // Sort by start time
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return solve(0, k, events, dp);
    }
};

