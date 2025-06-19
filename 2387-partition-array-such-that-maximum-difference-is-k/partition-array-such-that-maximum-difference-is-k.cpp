// class Solution {
// public:
//     int partitionArray(vector<int>& nums, int k) {
//         int n = nums.size();
//         int count = 0;
//         sort(nums.begin(), nums.end());
        
//         int i=0;
//         while(i < n){
//             int min = nums[i];
//             int j = i+1;
//             while(j < n && nums[j]-min <= k){
//                 j++;
//             }
//             count++;
//             i = j;
//         }
//         return count;
//     }
// };


class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        sort(nums.begin(), nums.end());
        
        int minVal = nums[0];
        for(int i=1; i<n; i++){
            if(nums[i]-minVal > k){
                count++;
                minVal = nums[i];
            }
        }
        count++;
        return count;
    }
};