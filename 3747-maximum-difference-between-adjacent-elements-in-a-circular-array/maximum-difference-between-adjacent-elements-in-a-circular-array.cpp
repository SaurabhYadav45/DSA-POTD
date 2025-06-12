class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int  result = 0;

        for(int i=0; i<n-1; i++){
            if(i == 0){
                result = max(result, abs(nums[0] - nums[n-1]));
                result = max(result, abs(nums[i] - nums[i+1]));
            }
            else{
                result = max(result, abs(nums[i] - nums[i+1]));
            }
        }
        return result;
    }
};