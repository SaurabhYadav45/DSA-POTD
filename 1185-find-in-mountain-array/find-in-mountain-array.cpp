/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findPivot(MountainArray &mountainArr){
        int n = mountainArr.length();
        int l = 0;
        int r = n-1;
        int pivotIdx = -1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(mid+1 < n && mountainArr.get(mid) > mountainArr.get(mid+1)){
                pivotIdx = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return pivotIdx;
    }

    int binarySearch(MountainArray &mountainArr, int target, int l, int r, bool sorted){
        int mid;
        while(l <= r){
            mid = l + (r-l)/2;
            if(mountainArr.get(mid) == target) return mid;
            if(sorted){
                if(mountainArr.get(mid) > target){
                    r = mid-1;
                }
                else{
                    l = mid+1;
                }
            }
            else{
                if(mountainArr.get(mid) < target){
                    r = mid-1;
                }
                else{
                    l = mid+1;
                }
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int pivotIdx = findPivot(mountainArr);
        if(mountainArr.get(pivotIdx) == target) return pivotIdx;

        int b1 = binarySearch(mountainArr, target, 0, pivotIdx, true);
        if(b1 != -1) return b1;

        int b2 = binarySearch(mountainArr, target, pivotIdx+1, n-1, false);
        return b2;
    }
};