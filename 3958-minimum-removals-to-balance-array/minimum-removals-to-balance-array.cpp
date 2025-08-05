//        **************** Sliding window **************

// class Solution {
// public:   
//     int minRemoval(vector<int>& nums, int k) {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());

//         int left = 0;
//         int right = 0;
//         int maxLength = 0;

//         while(right < n){
//             while(nums[right] > 1LL* nums[left]*k){
//                 left++;
//             }
//             maxLength = max(maxLength, right-left+1);
//             right++;
//         }
//         return n-maxLength;
//     }
// };



//      *************** Upper Bound ********************

class Solution {
public:   
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int maxLength = 0;
        for(int start = 0; start<n; start++){
            long long limit = 1LL*nums[start]*k;
            int end = upper_bound(nums.begin()+start, nums.end(), limit) - nums.begin() - 1;
            maxLength = max(maxLength, end-start+1);
        }
        return n - maxLength;
    }
};


//     **************** Binary Search ******************

// class Solution {
// public:
//     bool isPossible(vector<int>& nums, int k, int mid) {
//         int n = nums.size();
//         for (int i = 0; i <= mid; i++) {
//             int start = i;                  // Remove i from start
//             int end = n - (mid - i) - 1;    // Remove (mid-i) from end

//             int mini = nums[start];
//             int maxi = nums[end];

//             if (1LL * maxi <= 1LL * mini * k) {
//                 return true;
//             }
//         }
//         return false;
//     }

//     int minRemoval(vector<int>& nums, int k) {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());

//         int low = 0;
//         int high = n; 
//         int result = 0;
//         while (low <= high) {
//             int mid = low + (high - low) / 2;

//             if (isPossible(nums, k, mid)) {
//                 result = mid;
//                 high = mid - 1;
//             } else {
//                 low = mid + 1; 
//             }
//         }
//         return result;
//     }
// };