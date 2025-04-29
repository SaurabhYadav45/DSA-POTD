class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int maxValue = 0;
        for(int&num : nums){
            maxValue = max(maxValue, num);
        }

        int i=0;
        int j=0;
        long long count = 0;
        long long result = 0;
        while(j < n){
            if(nums[j] == maxValue){
                count++;
            }
            if(count == k){
                while(count == k && i < n){
                    result += n-j;
                    if(nums[i] == maxValue){
                        count--;
                    }
                    i++;
                }
            } 
            j++; 
        }
        return result;
    }
};