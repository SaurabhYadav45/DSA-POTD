class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> st;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++){
            while(!st.empty() && st.top() > nums[i]){
                    ans++;
                    st.pop();
                }
            if (st.empty() || st.top() != nums[i]){
                st.push(nums[i]);
            }
            
        }
        while(!st.empty() && st.top() != 0){
            ans++;
            st.pop();
        }
        return ans;
    }
};



// class Solution {
// public:
//     int minOperations(vector<int>& nums) {
//         int ops = 0;
//     int n = nums.size();

//     while (true) {
//         // Check if all elements are zero
//         bool allZero = true;
//         for (int num : nums) {
//             if (num != 0) {
//                 allZero = false;
//                 break;
//             }
//         }
//         if (allZero) break;

//         // Find the first non-zero segment
//         int i = 0;
//         while (i < n && nums[i] == 0) i++;
//         int j = i;
//         while (j < n && nums[j] != 0) j++;

//         // Subarray from i to j-1
//         int minVal = *min_element(nums.begin() + i, nums.begin() + j);

//         // Set all occurrences of minVal in this subarray to 0
//         for (int k = i; k < j; ++k) {
//             if (nums[k] == minVal) {
//                 nums[k] = 0;
//             }
//         }

//         ops++;
//     }

//     return ops;
//     }
// };