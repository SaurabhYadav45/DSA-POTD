class Solution {
public:
    int n;
    vector<vector<int>>result;
    set<vector<int>> st;
    void solve(vector<int>&nums, vector<int>temp, int i){
        if(i == n){
            if(temp.size() >= 2){
                st.insert(temp);
            }
            return;
        }

        // take the current element;
        if(temp.empty() || temp.back() <= nums[i]){
            temp.push_back(nums[i]);
            solve(nums, temp, i+1);
            temp.pop_back();  // Backtrack
        }

        // dont take cur element
        solve(nums, temp, i+1);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n = nums.size();
        vector<int>temp;
        solve(nums, temp, 0);
        result.assign(st.begin(), st.end());
        return result;
    }
};