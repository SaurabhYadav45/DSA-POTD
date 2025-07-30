class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        // Method-1
        int maxValue = *max_element(nums.begin(),nums.end());
        int ans = 0;
        int maxlength = 0;
        for(int num : nums){
            (num == maxValue)? maxlength++ : maxlength = 0;
            ans = max(ans, maxlength);
        }
        return ans;

        // Method-2
        // int maxValue = 0;
        // int maxLength = 0;
        // int ans = 0;
        // for(int num : nums){
        //     if(num > maxValue){
        //         maxValue = num;
        //         maxLength = 0;
        //         ans = 0;
        //     }

        //     if(num  == maxValue){
        //         maxLength++;
        //     }
        //     else{
        //         maxLength = 0;
        //     }

        //     ans = max(ans, maxLength);
        // }
        // return ans;
    }
};