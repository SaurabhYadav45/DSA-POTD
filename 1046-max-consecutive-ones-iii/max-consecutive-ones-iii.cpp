class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLength = 0;
        int i = 0, j=0;
        int zero = 0;

        while(j < n){
            if(nums[j] == 0) zero++;
            while(zero > k){
                if(nums[i] == 0) zero--;
                i++;
            }
            maxLength = max(maxLength, j-i+1);
            j++;
        }
        return maxLength;
    }
};


// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
//         int n = nums.size();
//         int maxlength = 0;

//         for(int i=0; i<n; i++){
//             int zero = 0;
//             for(int j=i; j<n; j++){
//                 if(nums[j] == 0) zero++;
//                 if(zero <= k){
//                     maxlength = max(maxlength, j-i+1);
//                 }
//                 if(zero > k) break;
//             }
//         }
//         return maxlength;
//     }
// };