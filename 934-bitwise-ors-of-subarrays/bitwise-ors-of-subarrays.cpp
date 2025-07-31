// class Solution {
// public:
//     int subarrayBitwiseORs(vector<int>& nums) {
//         int n = nums.size();

//         unordered_set<int>st;

//         for(int i=0; i<n; i++){
//             int temp = 0;
//             for(int j=i; j<n; j++){
//                 temp |= nums[j];
//                 st.insert(temp);
//             }
//         }
//         return st.size();
//     }
// };


class Solution {
public:
    int subarrayBitwiseORs(vector<int>& nums) {
        unordered_set<int>result;
        unordered_set<int>prev;

        for(int& x : nums){
            unordered_set<int>curr;
            curr.insert(x);
            for(const int& y : prev){
                curr.insert(x | y);
            }
            prev = curr;
            result.insert(curr.begin(), curr.end());
        }
        return result.size();
    }
};