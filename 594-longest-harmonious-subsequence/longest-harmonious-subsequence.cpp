class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int>mp;
        int result = 0;
        for(int&num :nums){
            mp[num]++;
        }

        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size()-1; i++){
            int mini = nums[i];
            int maxi = nums[i+1];
            if(maxi - mini == 1){
                result = max(result, mp[mini] + mp[maxi]);
            }
        }
        return result;
    }
};