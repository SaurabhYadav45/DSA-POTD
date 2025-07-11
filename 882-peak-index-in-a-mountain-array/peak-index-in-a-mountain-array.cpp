// class Solution {
// public:
//     int peakIndexInMountainArray(vector<int>& arr) {
        
//         int n= arr.size();
//         int s=0;
//         int e= n-1;
//         int mid = s + (e-s)/2;

//         while(s<e){
            
//             if(arr[mid] < arr[mid + 1]){
//                 s= mid+1;
//             }
//             else{
//                 e=mid;
//             }

//             mid = s + (e-s)/2;
//         }
//         return s;
//     }
// };


class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        int peak = -1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(mid+1 < n && nums[mid] > nums[mid+1]){
                peak = mid;
                r = mid-1;
            }
            else{
                l = mid + 1;
            }
        }
        return peak;
    }
};