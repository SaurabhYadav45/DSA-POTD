// class Solution {
// public:

//     void permuteUniqueHelper(vector<int>& nums,vector<vector<int>>&ans, int start){
//         // Base Case
//         if(start >=nums.size()){
//             ans.push_back(nums);
//             return;
//         }
        
//         unordered_map<int,bool>visited;
//         for(int i=start; i<nums.size(); i++){
            
//             if(visited.find(nums[i]) != visited.end()){
//                 continue;
//             }
//             visited[nums[i]] = true;
//             swap(nums[i],nums[start]);
//             permuteUniqueHelper(nums, ans, start+1);
//             //  Backtracking
//              swap(nums[i],nums[start]); 
//         }
//     }
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         vector<vector<int>>ans;
//         permuteUniqueHelper(nums, ans,0);


//         // set<vector<int>>st;
//         // for(auto e:ans){
//         //     st.insert(e);
//         // }
//         // ans.clear();

//         // for(auto e: st){
//         //     ans.push_back(e);
//         // }


//         return ans;
//     }
// };





class Solution {
public:
    int n;
    vector<vector<int>>result;

    void solve(unordered_map<int, int>&mp, vector<int>temp){
        if(temp.size() == n){
            result.push_back(temp);
            return;
        }

        for(auto&[num, count]: mp){
            if(count > 0){
                temp.push_back(num);
                mp[num]--;
                solve(mp, temp);
                // Backtracking
                temp.pop_back();
                mp[num]++;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, int>mp;
        n = nums.size();
        for(int&num: nums){
            mp[num]++;
        }

        vector<int>temp;
        solve(mp, temp);
        return result;
    }
};