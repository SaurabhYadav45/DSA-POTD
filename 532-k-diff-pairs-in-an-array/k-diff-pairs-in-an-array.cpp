// class Solution {
// public:
    
//     int bs(vector<int>nums, int start, int target){
//         int end = nums.size()-1;
//         int mid;
//         while(start <= end){
//             mid = start + (end-start)/2;
//             if(nums[mid] == target){
//                 return mid ;
//             }
//             else if(nums[mid] > target){
//                 end = mid-1;
//             }
//             else{
//                 start = mid + 1;
//             }
//         }
//         return -1;
//     }

//     int findPairs(vector<int>& nums, int k) {

//         // METHOD -2 : Binarysearch
//         sort(nums.begin(), nums.end());
//         set<pair<int, int>>ans;
//         for(int i=0; i< nums.size(); i++){

//             if(bs(nums, i+1, nums[i] + k) != -1){
//                 ans.insert({nums[i], nums[i] + k});
//             }
//         }
//         return ans.size();

//         // METHOD -1 : Two Pointer Approach

//         // sort(nums.begin(), nums.end());

//         // int i=0;
//         // int j=1;
//         // // int count=0;
//         // int diff;
//         // int n = nums.size();
//         // set<pair<int, int>>ans;
        
//         // while(j < n){
//         //      diff = nums[j] - nums[i];
            
//         //     if(diff == k){
//         //         ans.insert({nums[i], nums[j]});
//         //         i++;
//         //         j++;
//         //     }
//         //     else if(diff > k){
//         //         i++;
//         //     }
//         //     else{
//         //         j++;
//         //     }
//         //     if(i == j){
//         //         j++;
//         //     }
//         // }
//         // // return count;
//         // return ans.size();

        
//     }
// };



//             ************** Two Pointer **************

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int i=0, j = 1;
        set<pair<int, int>>st;
        while(j < n){
            if(i == j){
                j++; // edge case
                continue;
            }

            int diff = abs(nums[j] - nums[i]);
            if(diff == k){
                st.insert({nums[i], nums[j]});
                i++; j++;
            }
            else if(diff < k){
                j++;
            }
            else{
                i++; // diff > k
            }
        }
        return st.size();
    }
};