class Solution {
public:
    long long twoPointer(vector<int>&nums, int target){
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size()-1;
        long long result = 0;
        while(left < right){
            if(nums[left] + nums[right] < target){
                result  += right-left;
                left++;
            }
            else{
                right--;
            }
        }
        return result;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        long long ans = abs(twoPointer(nums, lower) - twoPointer(nums,upper+1));
        return ans;
    }
};


//                        Brute force 
//                        T.C = O(n^2)


// class Solution {
// public:
//     long long countFairPairs(vector<int>& nums, int lower, int upper) {
//         int n = nums.size();
//         int countPair = 0;
//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n; j++){
//                 if((nums[i] + nums[j] >= lower) && (nums[i] + nums[j] <= upper)){
//                     countPair++;
//                 }
//             }
//         }
//         return countPair;
//     }
// };