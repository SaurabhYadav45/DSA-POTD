// class Solution {
// public:
//     int countHillValley(vector<int>& nums) {
//         int n = nums.size();
//         vector<int>pSum(n, 0);
//         vector<int>pSum2(n, 0);
//         // pSum[0] = nums[0];
//         for(int i=1; i<n; i++){
//             if(nums[i] != nums[i-1]) pSum[i] = nums[i-1];
//             else pSum[i] = pSum[i-1]; 
//         }

//         // rSum[n-1] = 
//         for(int i=n-2; i>=0; i--){
//             if(nums[i] != nums[i+1]) pSum2[i] = nums[i+1];
//             else pSum2[i] = pSum2[i+1]; 
//         }

//         int count = 0;
//         bool hill = false;
//         bool valley = false;
//         for(int i=1; i<n-1; i++){
//             if(nums[i] > pSum[i] && nums[i] > pSum2[i]){
//                 count++;
//             }
//             else if(nums[i] < pSum[i] && nums[i] < pSum2[i]){
//                 count++;
//             }
//         }
//         return count;
//     }
// };



class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int res = 0;  // number of peaks and valleys
        int n = nums.size();
        for (int i = 1; i < n - 1; ++i) {
            if (nums[i] == nums[i - 1]) {
                // deduplication
                continue;
            }
            int left = 0;  // left side possibly unequal neighboring
                           // corresponding state
            for (int j = i - 1; j >= 0; --j) {
                if (nums[j] > nums[i]) {
                    left = 1;
                    break;
                } else if (nums[j] < nums[i]) {
                    left = -1;
                    break;
                }
            }
            int right = 0;  // right side possibly unequal neighboring
                            // corresponding state
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] > nums[i]) {
                    right = 1;
                    break;
                } else if (nums[j] < nums[i]) {
                    right = -1;
                    break;
                }
            }
            if (left == right && left != 0) {
                // at this time, index i is part of a peak or valley.
                ++res;
            }
        }
        return res;
    }
};