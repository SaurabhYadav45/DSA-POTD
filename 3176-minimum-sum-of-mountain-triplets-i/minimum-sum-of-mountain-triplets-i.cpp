class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();

        int minSum = INT_MAX;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k = j+1; k<n; k++){
                    if(nums[i] < nums[j] && nums[k] < nums[j]){
                        minSum = min(minSum, nums[i]+nums[j]+nums[k]);
                    }
                }
            }
        }
        int result = minSum == INT_MAX ? -1 : minSum;
        return result;
    }
};