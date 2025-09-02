class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        unordered_map<int, int>mp;
        mp[0] = 1;
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            if(mp.find(sum-k) != mp.end()){
                count += mp[sum-k];
            }
            mp[sum]++;
        }
        return count;
    }
};


// class Solution {
// public:
    // int subarraySum(vector<int>& nums, int k) {
    //     // Method -1 : Brute force
    //     int count = 0;
    //     for(int i=0; i<nums.size(); i++){
    //         int sum =0;
    //         for(int j=i; j<nums.size(); j++){
    //             sum += nums[j];
    //             if(sum  == k){
    //                 count++;
    //             }
    //         }
    //     }
    //     return count;
