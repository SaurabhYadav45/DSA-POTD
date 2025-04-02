class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long result = 0;

        vector<int>prefix(n), suffix(n);

        for(int i=1; i<n; i++){
            prefix[i] = max(prefix[i-1], nums[i-1]);
            suffix[n-i-1] = max(suffix[n-i], nums[n-i]);
        }

        for(int i=1; i<n-1; i++){
            result = max(result, (long long)(prefix[i] - nums[i])*suffix[i]);
        }
        
        return result;
    }
};


// class Solution {
// public:
//     long long maximumTripletValue(vector<int>& nums) {
//         int n = nums.size();

//         long long result = 0;

//         int maxPrefix = nums[0];
        
//         for(int j=1; j<n; j++){
//             for(int k= j+1; k<n; k++){
//                 result = max(result, (long long)(maxPrefix-nums[j])*nums[k]);
//                 maxPrefix = max(maxPrefix, nums[j]);
//             }
//         }
//         return result;
//     }
// };


// class Solution {
// public:
//     long long maximumTripletValue(vector<int>& nums) {
//         int n = nums.size();

//         long long maxSum = INT_MIN;

//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n; j++){
//                 for(int k = j+1; k<n; k++){
//                     long long sum  = (nums[i]-nums[j]);
//                     sum *= nums[k];
//                     maxSum = max(maxSum, sum);
//                 }
//             }
//         }
//         long long result =  maxSum > 0 ? maxSum : 0;
//         return result;
//     }
// };