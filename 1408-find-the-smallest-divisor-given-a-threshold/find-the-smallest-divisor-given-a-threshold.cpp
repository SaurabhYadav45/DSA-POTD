class Solution {
public:
    bool isPossible(vector<int>& nums, int& threshold, int& divisor){
        int sum = 0;
        for(int& num: nums){
            sum += ceil((float)num/divisor);
        }
        if(sum <= threshold){
            return true;
        }
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int result = -1;
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        while(low <= high){
            int mid = low + (high-low)/2;
            if(isPossible(nums, threshold, mid)){
                result = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return result;
    }
};



//          ************** Brute Force ***********

// class Solution {
// public:
//     int smallestDivisor(vector<int>& nums, int threshold) {
//         int result = -1;
//         int high = *max_element(nums.begin(), nums.end());
//         for(int divisor=1; divisor<=high; divisor++){
//             int sum = 0;
//             for(int& num: nums){
//                 sum += ceil((float)num/divisor);
//             }
//             if(sum <= threshold){
//                 result = divisor;
//                 break;
//             }
//         }
//         return result;
//     }
// };