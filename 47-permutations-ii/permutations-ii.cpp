// class Solution {
// public:
//     int n;
//     vector<vector<int>>result;

//     void solve(unordered_map<int, int>&mp, vector<int>temp){
//         if(temp.size() == n){
//             result.push_back(temp);
//             return;
//         }

//         for(auto&[num, count]: mp){
//             if(count > 0){
//                 temp.push_back(num);
//                 mp[num]--;
//                 solve(mp, temp);
//                 // Backtracking
//                 temp.pop_back();
//                 mp[num]++;
//             }
//         }
//     }
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         unordered_map<int, int>mp;
//         n = nums.size();
//         for(int&num: nums){
//             mp[num]++;
//         }

//         vector<int>temp;
//         solve(mp, temp);
//         return result;
//     }
// };




class Solution {
public:
    int n;
    vector<vector<int>>result;

    void solve(int start, vector<int>& nums){
        if(start >= n){
            result.push_back(nums);
            return;
        }

         unordered_set<int>st;
        for(int i=start; i<n; i++){
            if(st.find(nums[i]) != st.end()){
                continue;
            }
            st.insert(nums[i]);
            swap(nums[i], nums[start]);
            solve(start+1, nums);
            //Backtracking
            swap(nums[i], nums[start]);
            // st.erase(nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        
        solve(0, nums);
        return result;
    }
};