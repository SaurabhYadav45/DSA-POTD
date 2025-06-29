class Solution {
public:
    const int MOD = 1e9 + 7;
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        int j = n-1;
        int result = 0;

        vector<int>power(n+1, 0);
        power[0] = 1;
        for(int i=1; i<=n; i++){
            power[i] = power[i-1]*2 % MOD;
        }

        while(i <= j){
            if(nums[i] + nums[j] <= target){
                int diff = j-i;
                // result = ((int)result % MOD + ((int)pow(2, diff) % MOD)) % MOD;
                result = (result % MOD + power[diff]) % MOD;
                i++;
            }
            else if(nums[i] + nums[j] > target){
                j--;
            }
        }
        return result;
    }
};



//                                    TLE

// class Solution {
// public:
//     const int MOD = 1e9 + 7;
//     int numSubseq(vector<int>& nums, int target) {
//         sort(nums.begin(), nums.end());
//         int n = nums.size();
//         int i = 0;
//         int j = n-1;
//         int result = 0;

//         while(i <= j){
//             if(nums[i] + nums[j] <= target){
//                 int diff = j-i;
//                 result = ((int)result % MOD + ((int)pow(2, diff) % MOD)) % MOD;
//                 i++;
//             }
//             else if(nums[i] + nums[j] > target){
//                 j--;
//             }
//         }
//         return result;
//     }
// };