// class Solution {
// public:
//     int specialArray(vector<int>& nums) {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());
//         int l = 0, h = 1000;

//         while(l <= h){
//             int mid = l + (h-l)/2;
//             for(int& num: nums){

//             }
//         }
//     }
// };


//       **************** Brute Force : Linear seraching **************

class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<=n; i++){
            int count = 0;
            for(int& num : nums){
                if(num >= i)count++;
            }
            if(count == i) return i;
        }
        return -1;
    }
};
