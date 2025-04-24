class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n  = nums.size();
        unordered_set<int>st{nums.begin(), nums.end()};
        int distinct_size = st.size();

        int count = 0;

        for(int i=0; i<n; i++){
            unordered_set<int>temp;
            for(int j=i; j<n; j++){
                temp.insert(nums[j]);
                if(temp.size() == distinct_size){
                    count++;
                }
            }
        }
        return count;
    }
};