// class Solution {
// public:
//     bool isPossible(vector<int> nums, long long mid){
//         int n = nums.size();
//         for (int i = n - 1; i > 0; --i) {
//             if (nums[i] > mid) {
//                 long long reduce = nums[i] - mid;
//                 nums[i] -= reduce;
//                 nums[i - 1] += reduce;
//             }
//         }
//         return nums[0] <= mid;
//     }
//     int minimizeArrayValue(vector<int>& nums) {
//         long long low = 1;
//         long long high = *max_element(nums.begin(), nums.end());

//         long long result = 0;
//         while(low <= high){
//             long long mid = low + (high-low)/2;
//             if(isPossible(nums, mid)){
//                 result = mid;
//                 high = mid-1;
//             }
//             else{
//                 low = mid+1;
//             }
//         }
//         return result;
//     }
// };

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long sum = 0;
        int result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            result = max(result, (int)((sum + i) / (i + 1)));
        }
        return result;
    }
};
