class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long result = 0;
        
        int minIdx = -1;
        int maxIdx = -1;
        int culpritIdx = -1;

        for(int i=0; i<n; i++){
            if(nums[i] < minK || nums[i] > maxK){
                culpritIdx = i;
            }
            if(nums[i] == minK){
                minIdx = i;
            }
            if(nums[i] == maxK){
                maxIdx = i;
            }

            long long temp = min(minIdx, maxIdx) - culpritIdx;
            result += (temp <= 0) ? 0 : temp;
        }
        
        return result;
    }
};