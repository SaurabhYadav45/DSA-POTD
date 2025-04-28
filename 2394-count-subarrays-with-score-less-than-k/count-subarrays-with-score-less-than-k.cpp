class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();

        long long count = 0;
        int i=0;
        int j=0;

        long long sum = 0;
        long long score=0;

        while(j < n){
            sum += nums[j];
            score = sum * (j-i+1);

            while(score >= k){
                sum -= nums[i];
                i++;
                score = sum*(j-i+1);
            }
            count += j-i+1;
            j++;
        }
        return count;
    }
};





// class Solution {
// public:
//     bool validSubarray(vector<int>& nums, int i, int j, long long k){
//         long long sum = 0;
//         for(int k=i; k<=j; k++){
//             sum += nums[k];
//         }
//         if(sum * (j-i+1) < k){
//             return true;
//         }
//         return false;
//     }
//     long long countSubarrays(vector<int>& nums, long long k) {
//         int n = nums.size();

//         long long count = 0;

//         for(int i=0; i<n; i++){
//             for(int j=i; j<n; j++){
//                 if(validSubarray(nums, i, j, k)){
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };