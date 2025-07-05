class Solution {
public:
    int findLucky(vector<int>& nums) {
        unordered_map<int, int>mp;
        for(int&num: nums){
            mp[num]++;
        }

        int result = -1;

        for(auto& it: mp){
            if(it.first == it.second){
                result = max(result, it.first);
            }
        }
        return result;
    }
};