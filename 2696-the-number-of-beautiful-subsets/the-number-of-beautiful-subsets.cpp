class Solution {
public:
    int n;
    void solve(int i, vector<int>& nums, int k, unordered_map<int, int>&mp, int&result){
        if( i == n){
         result++;
            return;
        }

        // take
        if(!mp[nums[i] - k] && !mp[nums[i] + k]){
            mp[nums[i]]++;
            solve(i+1, nums, k, mp, result);
            //Backtrack
            mp[nums[i]]--;
            if(mp[nums[i]] == 0)mp.erase(nums[i]);
        }

        // skip
        solve(i+1, nums, k, mp, result);
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        int result = 0;
        unordered_map<int, int>mp;
        solve(0, nums, k, mp, result);
        return result-1;
    }
};