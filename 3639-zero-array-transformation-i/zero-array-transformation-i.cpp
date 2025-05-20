class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>pSum(n, 0);

        for(int i=0; i<queries.size(); i++){
            int l = queries[i][0];
            int r = queries[i][1];
            pSum[l] += 1;
            if(r+1 < n){
                pSum[r+1] -= 1;
            }
        }

        for(int i=1; i<n; i++){
            pSum[i] = pSum[i-1] + pSum[i];
        }

        for(int i=0; i<n; i++){
            nums[i] -= pSum[i];
            if(nums[i] > 0){
                return false;
            }
        }
        return true;
    }
};