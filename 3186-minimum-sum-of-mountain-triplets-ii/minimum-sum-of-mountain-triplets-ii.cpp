class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();

        vector<int>prefix(n), suffix(n);
        int result = INT_MAX;

        prefix[0] = nums[0];
        suffix[n-1] = nums[n-1];

        for(int i=1; i<n; i++){
            prefix[i] = min(prefix[i-1], nums[i-1]);
            suffix[n-i-1] = min(suffix[n-i], nums[n-i]); 
        }

        for(int i=1; i<n-1; i++){
            if(prefix[i] < nums[i] && suffix[i] < nums[i]){
                result = min(result, prefix[i] + nums[i] + suffix[i]);
            }
        }
        return result == INT_MAX ? -1 : result;
    }
};