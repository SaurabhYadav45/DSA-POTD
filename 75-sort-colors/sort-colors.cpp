class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0;  // denotes : 0
        int j=0;    // denotes : 1
        int k = n-1; // denotes : 2
        while(j <= k){
            if(nums[j] == 1){
                j++;
            }
            else if(nums[j] == 2){
                swap(nums[j], nums[k]);
                k--;
            }else{
                // nums[j] == 0
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
        }
    }
};
// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int n= nums.size();
//         int index=0;   // denotes : 1  
//         int left=0;    // denotes : 0
//         int right=n-1; // denotes : 2

//         while(index <= right){
//             if(nums[index] == 0){
//                 swap(nums[index], nums[left]);
//                 index++;
//                 left++;
//             }
//             else if(nums[index] == 2){
//                 swap(nums[index], nums[right]);
//                 right--;
//             }
//             else 
//             index++;
//         }
//     }
// };