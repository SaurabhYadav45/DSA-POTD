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


//     **************** Binary Search ******************

class Solution {
public:
    bool isPossible(vector<int>& nums, int k, int mid) {
        int n = nums.size();
        for (int i = 0; i <= mid; i++) {
            int start = i;                  // Remove i from start
            int end = n - (mid - i) - 1;    // Remove (mid-i) from end

            int mini = nums[start];
            int maxi = nums[end];

            if (1LL * maxi <= 1LL * mini * k) {
                return true;
            }
        }
        return false;
    }

    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int low = 0, high = n - 1, result = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPossible(nums, k, mid)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1; 
            }
        }
        return result;
    }
};




//      ******************* Wrong Solution *****************
//   Failed for tetscases where we need to delete element from start and end both side 

// class Solution {
// public:   
//     int minRemoval(vector<int>& nums, int k) {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());

//         for(int i=0; i<n; i++){
//             int mini1 = nums[0+i];
//             int maxi1 = nums[n-1];

//             int mini2 = nums[0];
//             int maxi2 = nums[n-1-i];

//             if(maxi1 <= mini1*k){
//                 return i;
//             }
//             else if(maxi2 <= mini2*k){
//                 return i;
//             }
//         }
//         return -1;
//     }
// };