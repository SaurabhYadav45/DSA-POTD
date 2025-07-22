class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st;
        int sum = 0;
        int result = -1;
        int i=0, j=0;
        while(j < n){
            while(st.find(nums[j]) != st.end()){
                sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }
            sum += nums[j];
            st.insert(nums[j]);
            result = max(result, sum);
            j++;
        }
        return result;
    }
};