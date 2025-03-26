class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();

        // sort(nums.begin(), nums.end());

        // partial sorting
        nth_element(nums.begin(), nums.begin()+ n/2, nums.end());

        int median = nums[n/2];

        int minMove = 0;

        for(int& num : nums){
            minMove += abs(median - num)/1;
        }
        return minMove;
    }
};