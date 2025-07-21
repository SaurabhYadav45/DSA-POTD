class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>freq(n+1, 0);
        for(int i=0; i<n; i++){
            if(nums[i] >= n){
                freq[n]++;
            }
            else{
                freq[nums[i]]++;
            }
        }

        if(freq[n] == n) return n;
        for(int i=n-1; i>=0; i--){
            freq[i] += freq[i+1];
            if(freq[i] == i) return i;
        }
        return -1;
    }
};


//           **************** Binary Search ***********

// class Solution {
// public:
//     int specialArray(vector<int>& nums) {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());
//         int l = 0, h = n;

//         while(l <= h){
//             int mid = l + (h-l)/2;
//             int i = lower_bound(nums.begin(), nums.end(), mid)- nums.begin();
//             if(n-i > mid){
//                 l = mid+1;
//             }
//             else if(n-i < mid){
//                 h = mid-1;
//             }
//             else{
//                 return mid;
//             }
//         }
//         return -1;
//     }
// };


//       **************** Brute Force **************

// class Solution {
// public:
//     int specialArray(vector<int>& nums) {
//         int n = nums.size();
//         for(int i=0; i<=n; i++){
//             int count = 0;
//             for(int& num : nums){
//                 if(num >= i)count++;
//             }
//             if(count == i) return i;
//         }
//         return -1;
//     }
// };
