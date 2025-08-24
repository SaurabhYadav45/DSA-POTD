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
                if(count == 2){
                    int l = j-i-1;
                    result = max(result, l);

                    while(nums[i] != 0){
                        i++;
                    }
                    i++;
                    count--;
                }
            }
            j++;
        }
        if(count == 0 || count == 1){
            result = max(result, j-i-1);
        }
        return result;
    }
};