class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int count = 0;
        int sum = 0;
        unordered_map<int, int>mp;
        mp[0] = 1;

        for(int i=0; i<n; i++){
            sum += nums[i];
            if(mp.find(sum-goal) != mp.end()){
                count += mp[sum-goal];
            }
            mp[sum]++;
        }
        return count;
    }
};

//      **************** Brute Force *************

// class Solution {
// public:
//     int numSubarraysWithSum(vector<int>& nums, int goal) {
//         int n = nums.size();
//         int count = 0;

//         for(int i=0; i<n; i++){
//             int sum = 0;
//             for(int j=i; j<n; j++){
//                 sum += nums[j];
//                 if(sum == goal) count++;
//             }
//         }
//         return count;
//     }
// };