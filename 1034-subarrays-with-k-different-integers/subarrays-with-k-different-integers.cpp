class Solution {
public:
    int solve(vector<int>& nums, int k){
        if(k < 0) return 0;
        int n = nums.size();
        int count = 0;
        unordered_map<int, int>mp;
        int i=0, j=0;

        while(j < n){
            mp[nums[j]]++;
            while(mp.size() > k){
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            count = count + (j-i+1);
            j++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int result1 = solve(nums, k);
        int result2 = solve(nums, k-1);
        return result1 - result2;
    }
};