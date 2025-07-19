class Solution {
public:
    int countValidPairs(vector<int>& nums, int threshold) {
        int index = 0, count = 0;
        while (index < nums.size() - 1) {
            if (nums[index + 1] - nums[index] <= threshold) {
                count++;
                index++;
            }
            index++;
        }
        return count;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums[n-1] - nums[0];
        int result = 0;
        while(left <= right){
            int mid = left + (right-left)/2;

            if(countValidPairs(nums, mid) >= p){
                result = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return result;
    }
};