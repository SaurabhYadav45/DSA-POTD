class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();

        long long maxSum = INT_MIN;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k = j+1; k<n; k++){
                    long long sum  = (nums[i]-nums[j]);
                    sum *= nums[k];
                    maxSum = max(maxSum, sum);
                }
            }
        }
        long long result =  maxSum > 0 ? maxSum : 0;
        return result;
    }
};