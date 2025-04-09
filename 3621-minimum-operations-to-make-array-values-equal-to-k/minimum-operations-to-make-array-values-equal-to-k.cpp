class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int>st;
        for(int&num: nums){
            st.insert(num);
        }

        int count = 0;
        for(const int& num : st){
            if(num < k)return -1;
           if(num > k)count++;
        }
        return count;
    }
};