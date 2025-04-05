class Solution {
public:
    int n;
    void getSubset(vector<int>& nums, int i, vector<vector<int>>&subsets, vector<int>subset){
        if(i == n){
            subsets.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        getSubset(nums, i+1, subsets, subset);
        subset.pop_back();
        getSubset(nums, i+1, subsets, subset);
    }
    int subsetXORSum(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>>subsets;

        getSubset(nums, 0, subsets, {});

        int xor_sum = 0;

        for(auto& subset: subsets){
            int x_or = 0;
            for(int& num : subset){
                x_or ^= num;
            }
            xor_sum += x_or;
        }
        return xor_sum;
    }
};