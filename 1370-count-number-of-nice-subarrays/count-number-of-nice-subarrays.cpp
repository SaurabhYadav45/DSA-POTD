class Solution {
public:
    int solve(vector<int>& nums, int k){
        int n = nums.size();
        if(k < 0) return 0;

        int count = 0;
        int sum = 0;
        int i=0, j=0;

        while( j < n){
            sum += (nums[j] % 2);
            while(sum > k){
                sum -= (nums[i] % 2);
                i++;
            }
            count += (j-i+1);
            j++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int result1 = solve(nums, k);
        int result2 = solve(nums, k-1);
        return result1-result2;
    }
};

// class Solution {
// public:
//     int numberOfSubarrays(vector<int>& nums, int k) {
//         int n = nums.size();
//         unordered_map<int, int>mp;
//         int count = 0;
//         int sum = 0;
//         mp[0] = 1;

//         for(int i=0; i<n; i++){
//             sum += (nums[i] % 2);
//             if(mp.find(sum-k) != mp.end()){
//                 count += mp[sum-k];
//             }
//             mp[sum]++;
//         }
//         return count;
//     }
// };
