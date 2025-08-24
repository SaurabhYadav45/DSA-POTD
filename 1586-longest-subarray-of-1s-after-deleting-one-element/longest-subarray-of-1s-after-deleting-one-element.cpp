class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i=0, j=0;
        int count = 0;
        int result = INT_MIN;
        while(j < n){
            if(nums[j] == 0){
                count++;
            }
            while(count > 1){
                if(nums[i] == 0) count--;
                i++;
            }
            result = max(result, j-i);
            j++;
        }
        return result;
    }
};