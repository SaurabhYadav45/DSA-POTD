class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>>result;

        for(int i=0; i<n-2; i = i+3){
            if(nums[i+2] - nums[i] <= k){
                result.push_back({nums[i], nums[i+1], nums[i+2]});
            }
            else{
                return {};
            }
        }
        return result;
    }
};



// class Solution {
// public:
//     vector<vector<int>> divideArray(vector<int>& nums, int k) {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());

//         vector<vector<int>>result;
//         vector<int>vec;

//         for(int i=0; i<n; i++){
//             if(!vec.empty() && abs(nums[i] - vec.front()) > k){
//                 return {};
//             }
//             vec.push_back(nums[i]);
//             if(vec.size() == 3){
//                 result.push_back(vec);
//                 vec.clear();   // T.C = O(n)
//             }
//         }
//         return result;
//     }
// };


// class Solution {
// public:
//     vector<vector<int>> divideArray(vector<int>& nums, int k) {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());

//         vector<vector<int>>result;
//         vector<int>vec(3);

//         for(int i=0; i<n; i++){
//             if((i % 3 > 0) && abs(nums[i] - vec.front()) > k){
//                 return {};
//             }
//             vec[i % 3] = nums[i];
//             if(i % 3 == 2){
//                 result.push_back(vec);
//             }
//         }
//         return result;
//     }
// };
