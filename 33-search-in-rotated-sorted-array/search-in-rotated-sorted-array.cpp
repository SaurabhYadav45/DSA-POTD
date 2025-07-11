class Solution {
public:
    int findPivot(vector<int>& nums){
        int n = nums.size();
        int l = 0, r = n - 1;

        // while (l <= r) {
        //     int mid = l + (r - l) / 2;

        //     if (mid < n - 1 && nums[mid] > nums[mid + 1]) {
        //         return mid;
        //     }

        //     if (nums[mid] >= nums[l]) {
        //         l = mid + 1;
        //     } else {
        //         r = mid - 1;
        //     }
        // }
        // return -1;
        while(l < r){
            int mid = l + (r-l)/2;
            if(nums[mid] > nums[r]){
                l = mid+1;
            }
            else{
                r = mid;
            }
        }
        return r;  // or L
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

        if(nums[pivotIdx] == target) return pivotIdx;

        // if (pivotIdx == -1) {
        //     return binarySearch(0, n - 1, nums, target);
        // }

        int leftAns = binarySearch(0, pivotIdx-1, nums,  target);
            if(leftAns != -1) return leftAns;

        int rightAns = binarySearch(pivotIdx, n-1, nums,  target);
            if(rightAns != -1) return rightAns;
        return -1;
    }
};
