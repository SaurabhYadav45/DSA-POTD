class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long result = 0;
        
        stack<int>st;
        for(int i=0; i<=n; i++){
            while(!st.empty() && (i == n || nums[i] >= nums[st.top()])){
                int curr = st.top(); st.pop();
                int prev = st.empty() ? -1 : st.top();
                int next = i;
                int left = curr - prev;
                int right = next - curr;
                result += (long long)nums[curr]*left*right;
            }
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        for(int i=0; i<=n; i++){
            while(!st.empty() && (i == n || (nums[i] <= nums[st.top()]))){
                int curr = st.top(); st.pop();
                int prev = st.empty() ? -1 : st.top();
                int next = i;
                int left = curr - prev;
                int right = next - curr;
                result -= (long long)nums[curr]*left*right;
            }
            st.push(i);
        }
        return result;
    }
};



// class Solution {
// public:
//     long long subArrayRanges(vector<int>& nums) {
//         int n = nums.size();
//         long long result = 0;
        
//         for(int i=0; i<n; i++){
//             long long mini = INT_MAX;
//             long long maxi = INT_MIN;
//             for(int j=i; j<n; j++){
//                 mini = min(mini, (long long)nums[j]);
//                 maxi  =max(maxi, (long long)nums[j]);
//                 result += maxi- mini;
//             }
//         }
//         return result;
//     }
// };