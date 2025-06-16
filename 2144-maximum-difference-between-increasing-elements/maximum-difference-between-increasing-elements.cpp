// class Solution {
// public:
//     int maximumDifference(vector<int>& nums) {
//         int n = nums.size();
//         int result = -1;

//         for(int i=0; i<n; i++){
//             for(int j=i; j<n; j++){
//                 if(nums[i] < nums[j]){
//                     result = max(result, nums[j]-nums[i]);
//                 }
//             }
//         }
//         return result;
//     }
// };


class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int result = -1;

        vector<int>pSum(n, 0);
        pSum[n-1] = nums[n-1];

        for(int i=n-2; i>=0; i--){
            pSum[i] = max(nums[i], pSum[i+1]);
        }
        
        for(int i=0; i<n; i++){
            if(nums[i] < pSum[i]){
                result = max(result, pSum[i] - nums[i]);
            }
        }
        return result;
    }
};