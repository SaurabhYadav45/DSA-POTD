class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        long long result = 0;

        vector<int>pSum(n, 0);

        for(int i=0; i<n; i++){
            pSum[i] = (nums[i] % modulo == k ? 1 : 0);
        }

        unordered_map<int, long long>mp;
        mp[0] = 1;
        long long sum = 0;
        for(int i=0; i<pSum.size(); i++){
            sum += pSum[i];
            int r1 = sum % modulo;
            int r2 = (r1-k + modulo)%modulo;
            result += mp[r2];
            mp[r1]++;
        }
        return result;
    }
};


// class Solution {
// public:
//     long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
//         int n = nums.size();
//         int result = 0;

//         for(int i=0; i<n; i++){
//             int count = 0;
//             for(int j=i; j<n; j++){
//                 if(nums[j] % modulo == k){
//                     count++;
//                 }
//                 if(count % modulo == k){
//                     result++;
//                 }
//             }
//         }
//         return result;
//     }
// };