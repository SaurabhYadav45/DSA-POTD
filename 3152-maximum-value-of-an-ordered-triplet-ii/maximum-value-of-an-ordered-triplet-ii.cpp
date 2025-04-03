class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();

        long long highest = 0;
        long long highestDiff = 0;
        long long result = 0;

        for(long long num : nums){
            result = max(result, highestDiff*num);
            highestDiff = max(highestDiff, highest-num);
            highest = max(highest, num);
        }
        return result >0 ? result : 0;
    }
};




//                          Using Prefix Sum

// class Solution {
// public:
//     long long maximumTripletValue(vector<int>& nums) {
//         int n = nums.size();

//         vector<long long>prefix(n), suffix(n);

//         for(int i=1; i<n; i++){
//             prefix[i] = max(prefix[i-1], (long long)nums[i-1]);
//             suffix[n-i-1] = max(suffix[n-i], (long long)nums[n-i]);
//         }

//         long long maxSum = INT_MIN;

//         for(int i=1; i<n-1; i++){
//             maxSum = max(maxSum, (long long)(prefix[i]-nums[i])*suffix[i]);
//         }
//         long long result = maxSum >0 ? maxSum : 0;
//         return result;
//     }

// };