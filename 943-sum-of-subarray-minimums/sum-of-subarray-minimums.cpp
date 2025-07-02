class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<int>findNSL(vector<int>& nums, int n){
        stack<int>st;
        vector<int>NSL(n, 0);
        for(int i=0; i<n; i++){
            if(st.empty()){
                NSL[i] = -1;
            }
            else{
                while(!st.empty() && nums[st.top()] > nums[i]){
                    st.pop();
                }
                if(st.empty()){
                    NSL[i] = -1;
                }
                else{
                    NSL[i] = st.top();
                }
            }
            st.push(i);
        }
        return NSL;
    }

    vector<int>findNSR(vector<int>& nums, int n){
        stack<int>st;
        vector<int>NSR(n, 0);
        for(int i=n-1; i >= 0; i--){
            if(st.empty()){
                NSR[i] = n;
            }
            else{
                while(!st.empty() && nums[st.top()] >= nums[i]){
                    st.pop();
                }
                if(st.empty()){
                    NSR[i] = n;
                }
                else{
                    NSR[i] = st.top();
                }
            }
            st.push(i);
        }
        return NSR;
    }
    int sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();
        long long result = 0;
        vector<int>NSL = findNSL(nums, n);
        vector<int>NSR = findNSR(nums, n);

        for(int i=0; i<n; i++){
            long long ls = i - NSL[i];
            long long rs = NSR[i] - i;
            long long temp = ls*rs*nums[i] % MOD;
            result = (result + temp) % MOD;
        }
        return result;
    }
};


//          ****************** Brute Force *****************

// class Solution {
// public:
//     const int MOD = 1e9 + 7;
//     int sumSubarrayMins(vector<int>& nums) {
//         int n = nums.size();
//         int result = 0;

//         for(int i=0; i<n; i++){
//             int mini = INT_MAX;
//             for(int j=i; j<n; j++){
//                 mini = min(nums[j], mini);
//                 result = (result + mini ) % MOD;
//             }
//         }
//         return result;
//     }
// };