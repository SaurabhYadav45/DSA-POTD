class Solution {
public:
    int findPivot(vector<int>& nums){
        int n = nums.size();
        int l= 0;
        int r = n-1;
        while(l < r){
            while(l < r &&  nums[l] == nums[l+1]){
                l++;
            }

            while(l < r && nums[r] == nums[r-1]){
                r--;
            }
            int mid = l + (r-l)/2;
            
            if(nums[mid] > nums[r]){
                l = mid+1;
            }
            else{
                r = mid;
            }
        }
        return r;
    }

    bool binarySearch(int l, int r, vector<int>& nums, int target){
        int n = nums.size();
        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target){
                return true;
            }
            else if(nums[mid] > target){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int  pivotIdx = findPivot(nums);
        if(nums[pivotIdx] == target) return true;

        bool leftAns = binarySearch(0, pivotIdx-1, nums,  target);
            if(leftAns) return leftAns;

        bool rightAns = binarySearch(pivotIdx, n-1, nums,  target);
            if(rightAns) return rightAns;
        
        return false;
    }
};




// class Solution {
// public:
//     bool search(vector<int>& nums, int target) {
//         // for(int i=0; i<nums.size(); i++){
//         //     if(nums[i] == target){
//         //         return true;
//         //     }
//         // }
//         // return false;

//         int start =0;
//         int end = nums.size()-1;
//         int midHigh = nums.size()/2;
//         int midLow = nums.size()/2;
//         while(start <= end && midLow >=0 && midHigh < nums.size()){
//             if(nums[start] == target) return true;
//             start++;
//             if(nums[end ] == target) return true;
//             end--;
//             if(nums[midHigh] == target) return true;
//             midHigh++;
//             if(nums[midLow] == target) return true;
//             midLow--;
//         }
//         return  false;
//     }
// };



// class Solution {
// public:
//     int findPivot(vector<int>& nums){
//         int n = nums.size();
//         int l= 0;
//         int r = n-1;
//         if(nums[0] <= nums[n-1]) return -1; // If array is not rotated
//         while(l < r){
//             int mid = l + (r-l)/2;
//             if(mid+1 < n && nums[mid] > nums[mid+1]){
//                 return mid;
//             }
//             else if(mid-1 >= 0 && nums[mid] < nums[mid-1]){
//                 return mid-1;
//             }
//             else if(nums[mid] >= nums[l]){
//                 l = mid+1;
//             }
//             else{
//                 r = mid-1;
//             }
//         }
//         return -1;
//     }

//     bool binarySearch(int l, int r, vector<int>& nums, int target){
//         int n = nums.size();
//         while(l < r){
//             int mid = l + (r-l)/2;
//             if(nums[mid] == target){
//                 return true;
//             }
//             else if(nums[mid] > target){
//                 r = mid-1;
//             }
//             else{
//                 l = mid+1;
//             }
//         }
//         return false;
//     }
//     bool search(vector<int>& nums, int target) {
//         int n = nums.size();
//         int  pivotIdx = findPivot(nums);
//         if(target >= nums[0] && target <= nums[pivotIdx]){
//             bool leftAns = binarySearch(0, pivotIdx, nums, target);
//             if(leftAns) return true;
//         }
//         else{
//             bool rightAns = binarySearch(0, pivotIdx, nums, target);
//             if(rightAns) return true;
//         }
//         return false;
//     }
// };