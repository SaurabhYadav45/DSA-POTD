class Solution {
public:
    string triangleType(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=0; j<n; j++){
                if(i == j)continue;
                sum += nums[j];
            }
            if(sum <= nums[i]){
                return "none";
            }
        }
        
        unordered_set<int>st{nums.begin(), nums.end()};
        if(st.size() == 1){
            return "equilateral";
        }
        else if(st.size() == 2){
            return "isosceles";
        }
        return "scalene";
    }
};