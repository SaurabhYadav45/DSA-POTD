class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int>result;

        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size(); i++){
            int num = nums[i];
            if(num == target){
                result.push_back(i);
            }
        }
        return result;
    }
};