class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long result = 0;
        
        for(int i=0; i<n; i++){
            long long mini = INT_MAX;
            long long maxi = INT_MIN;
            for(int j=i; j<n; j++){
                mini = min(mini, (long long)nums[j]);
                maxi  =max(maxi, (long long)nums[j]);
                result += maxi- mini;
            }
        }
        return result;
    }
};