class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        int mid;
        int result = INT_MAX;
        while(l <= r){
            mid = l+(r-l)/2;
            if(nums[mid] > nums[r]){
                l = mid+1;
            }
            else if(nums[mid] < nums[r]){
                result = min(result, nums[mid]);
                r = mid-1;
            }
            else{
                result = min(result, nums[mid]);
                break;
            }
        }
        return result;
    }
};