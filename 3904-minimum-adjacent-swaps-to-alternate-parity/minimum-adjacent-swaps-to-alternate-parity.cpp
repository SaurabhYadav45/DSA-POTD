class Solution {
public:
    int count_even_swap(vector<int>&nums){
        int curr = 0;
        int swap = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] % 2 == 0){
                swap += abs(curr-i);
                curr += 2;
            }
        }
        return swap;
    }

    int count_odd_swap(vector<int>&nums){
        int curr = 0;
        int swap = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] % 2 != 0){
                swap += abs(curr-i);
                curr += 2;
            }
        }
        return swap;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int even_count = 0;
        int odd_count = 0;

        int result = 0;

        for(int&num: nums){
            if(num % 2 == 0){
                even_count++;
            }
        }
        odd_count = n - even_count ;

        if(abs(even_count - odd_count) > 1) return -1;

        if(even_count > odd_count){
            result = count_even_swap(nums);
        }
        else if(even_count < odd_count){
            result = count_odd_swap(nums);
        }
        else{
            result = min(count_even_swap(nums), count_odd_swap(nums));
        }
        return result;
    }
};