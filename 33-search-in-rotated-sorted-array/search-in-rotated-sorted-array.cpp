// class Solution {
// public:
//     int findPivotIndex(vector<int>&nums){
//         int n = nums.size();
//         int s = 0;
//         int e = n-1;
//         int mid = s + (e-s)/2;
//         while(s<=e){
//             // corner case
//             if(s==e){
//                 return s;
//             }
//             else if(mid+1 < n && nums[mid] > nums[mid+1]){
//                 return mid;
//             }
//             else if(mid-1>=0 && nums[mid] < nums[mid-1]){
//                 return mid-1;
//             }
//             else if(nums[s] > nums[mid]){
//                 e = mid-1;
//             }
//             else{
//                 s = mid + 1;
//             }

//             mid = s + (e-s)/2;
//         }
//         return -1;
//     }

//     int binarySearch(vector<int>&arr, int s, int e, int target){
//         int mid = s + (e-s)/2;
//         while(s<=e){
//             if(arr[mid] == target){
//                 return mid;
//             }
//             else if(arr[mid] > target){
//                 e = mid -1;
//             }
//             else{
//                 s = mid +1 ;
//             }
//             mid = s + (e-s)/2;
//         }
//         return -1;
//     }

//     int search(vector<int>& nums, int target) {
        
//         int pivotIndex = findPivotIndex(nums);
//         int n = nums.size();
//         int ans = -1;
//         if(target >= nums[0] && target <=nums[pivotIndex]){
//             ans = binarySearch(nums, 0, pivotIndex, target);
//         }
//         else{
//             ans = binarySearch(nums, pivotIndex +1, n-1, target);
//         }
//         return ans;
        
//     }
// };



class Solution {
public:
    int findPivot(vector<int>& nums){
        int n = nums.size();
        int l = 0, r = n - 1;
        
        if (nums[l] < nums[r]) return -1; // not rotated

        while (l <= r) {
            int mid = l + (r - l) / 2;

            // check if mid is the pivot
            if (mid < n - 1 && nums[mid] > nums[mid + 1]) {
                return mid;
            }

            if (nums[mid] >= nums[l]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return -1;
    }

    int binarySearch(int l, int r, vector<int>& nums, int target){
        while(l <= r){
            int mid  = l + (r-l)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivotIdx = findPivot(nums);
        // return pivotIdx;

        if (pivotIdx == -1) {
            return binarySearch(0, n - 1, nums, target);
        }

        if(target >= nums[0] && target <= nums[pivotIdx]){
            int leftAns = binarySearch(0, pivotIdx, nums,  target);
            if(leftAns != -1) return leftAns;
        }
        else{
            int rightAns = binarySearch(pivotIdx+1, n-1, nums,  target);
            if(rightAns != -1) return rightAns;
        }
        return -1;
    }
};
