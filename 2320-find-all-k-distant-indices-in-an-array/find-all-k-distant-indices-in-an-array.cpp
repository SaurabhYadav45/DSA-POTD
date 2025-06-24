class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int>result;
        unordered_set<int>st;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(abs(i-j) <= k && nums[j] == key){
                    st.insert(i);
                }
            }
        }
        result.assign(st.begin(), st.end());
        sort(result.begin(), result.end());
        return result;
    }
};