class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>mp;
        int count = 0;
        int sum = 0;
        mp[0] = 1;

        for(int i=0; i<n; i++){
            sum += (nums[i] % 2);
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
//     int numberOfSubarrays(vector<int>& nums, int k) {
//         // METHOD - 1 : Using Map
//         // unordered_map<int, int>mp;
//         // int oddCount = 0;
//         // int result=0;
//         // mp[oddCount] = 1;
//         // for(int i=0; i<nums.size();i++){
//         //     oddCount += (nums[i] % 2);
//         //     if(mp[oddCount-k]){
//         //         result += mp[oddCount -k];
//         //     }
//         //     mp[oddCount]++;
//         // }
//         // return result;


//         // Method-2 : Sliding Window;
//         int result =0;
//         int prevCount =0;
//         int oddCount =0;
//         int i=0;
//         int j=0;
//         while(j<nums.size()){
//             if(nums[j] % 2 != 0){
//                 oddCount++;
//                 prevCount = 0;
//             }
//             while(oddCount == k){
//                 prevCount++;
//                 if(nums[i]%2 == 1){
//                     oddCount--;
//                 }
//                 i++;
//             }
//             result += prevCount;
//             j++;
//         }
//         return result;
//     }
// };