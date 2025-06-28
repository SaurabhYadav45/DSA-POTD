class Solution {
public:
    static bool myComp(pair<int, int>&a, pair<int, int>&b){
        return a.second < b.second;
    }
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>result;

        vector<pair<int, int>>pairs;
        for(int i=0; i<n; i++){
            pairs.push_back({nums[i], i});
        }

        sort(pairs.rbegin(), pairs.rend());
        vector<pair<int, int>>temp;
        for(int i=0; i<k; i++){
            temp.push_back(pairs[i]);
        }

        sort(temp.begin(), temp.end(), myComp);
        for(auto& p : temp){
            result.push_back(p.first);
        }
        return result;
    }
};




// class Solution {
// public:
//     int n;
//     void solve(int i, vector<int>& nums, int k, int sum, int& maxSum, vector<int>&temp, vector<int>&result){
//         if(k == 0){
//             if(sum > maxSum){
//                 maxSum = sum;
//                 result = temp;
//             }
//             return;
//         }

//         if(i >= n){
//             return;
//         }
        
//         // take
//         temp.push_back(nums[i]);
//         solve(i+1, nums, k-1, sum+nums[i], maxSum, temp, result);
//         temp.pop_back();
//         //skip
//         solve(i+1, nums, k, sum, maxSum, temp, result);
//     }
//     vector<int> maxSubsequence(vector<int>& nums, int k) {
//         n = nums.size();
//         int maxSum = INT_MIN;
//         vector<int>result;
//         vector<int>temp;
//         solve(0, nums, k, 0, maxSum, temp, result);
//         return result;
//     }
// };