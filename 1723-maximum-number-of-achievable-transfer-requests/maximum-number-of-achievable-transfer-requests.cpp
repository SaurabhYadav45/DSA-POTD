class Solution {
public:
    int result =0;
    int m;
    bool checkResultant(vector<int>&resultant){
        for(int& num : resultant){
            if(num != 0){
                return false;
            }
        }
        return true;
    }
    void solve(int n, vector<vector<int>>& requests, int count, int idx, vector<int>&resultant){
        if(idx == m){
            if(checkResultant(resultant)){
                result = max(result, count);
            }
            return;
        }

        // take request
        resultant[requests[idx][0]]--;
        resultant[requests[idx][1]]++;
        //Explore
        solve(n, requests, count+1, idx+1, resultant);
        //Backtrack
        resultant[requests[idx][0]]++;
        resultant[requests[idx][1]]--;

        // Reject request
        solve(n, requests, count, idx+1, resultant);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        m = requests.size();
        result = 0;
        int count = 0;
        vector<int>resultant(n, 0);
        solve(n, requests, count, 0, resultant);
        return result ;
    }
};