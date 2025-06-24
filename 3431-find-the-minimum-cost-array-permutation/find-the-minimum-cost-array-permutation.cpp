class Solution {
public:
    vector<int>result;
    int minScore=INT_MAX;
    int n;
    void solve(vector<int>& nums, vector<int>& perm, vector<bool>&visited, int score){
        if(score > minScore) return;
        if(perm.size() == n){
            score += abs(perm.back() - nums[perm[0]]);
            if(score < minScore){
                minScore = score;
                result = perm;
            }
            return;
        }

        for(int num=0; num <n; num++){
            if(!visited[num]){
                visited[num] = true;
                perm.push_back(num);
                int size = perm.size();
                solve(nums, perm, visited, score + abs(perm[size-2] - nums[perm[size-1]]));
                //Backtrack
                visited[num] = false;
                perm.pop_back();
            }
        }
    }
    vector<int> findPermutation(vector<int>& nums) {
        n = nums.size();
        vector<bool>visited(n, false);
        vector<int>perm = {0};
        visited[0] = true;
        solve(nums, perm, visited, 0);
        return result;
    }
};