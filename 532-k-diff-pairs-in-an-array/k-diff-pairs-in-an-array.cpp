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
//     }
// };


class Solution {
public:
    bool binarySearch(vector<int>& nums, int target, int l){
        int n = nums.size();
        int r = n-1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target) return true;
            else if(nums[mid] < target){
                l = mid+1;
            }
            else{
                r  = mid-1;
            }
        }
        return false;
    }
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int count = 0;

        for(int i=0; i<n; i++){
            if(i != 0 && nums[i] == nums[i-1]) continue;
            int target = nums[i] +  k;
            if(binarySearch(nums, target, i+1)){
                count++;
            }
        }
        return count;
    }
};




//             ************** Two Pointer **************

// class Solution {
// public:
//     int findPairs(vector<int>& nums, int k) {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());

//         int i=0, j = 1;
//         set<pair<int, int>>st;
//         while(j < n){
//             if(i == j){
//                 j++; // edge case
//                 continue;
//             }

//             int diff = abs(nums[j] - nums[i]);
//             if(diff == k){
//                 st.insert({nums[i], nums[j]});
//                 i++; j++;
//             }
//             else if(diff < k){
//                 j++;
//             }
//             else{
//                 i++; // diff > k
//             }
//         }
//         return st.size();
//     }
// };