class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int>mp;
        int result = 0;
        for(int&num :nums){
            mp[num]++;
        }

        unordered_set<int>st(nums.begin(), nums.end());

        for(int& num : nums){
            int minCount = mp[num];
            if(st.find(num+1) == st.end()){
                continue;
            }
            int maxCount = mp[num+1];
            result = max(result, minCount + maxCount);
        }
        return result;
    }
};