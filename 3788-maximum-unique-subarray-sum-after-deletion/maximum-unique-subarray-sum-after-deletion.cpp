class Solution {
public:
    int maxSum(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        if(maxi  < 0) return maxi;
        
        unordered_set<int>st;
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > 0 && st.find(nums[i]) == st.end()){
                sum += nums[i];
                st.insert(nums[i]);
            }
        }
        return sum;
    }
};