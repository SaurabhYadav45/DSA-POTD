class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefixSum;
        unordered_map<int, int>mp;

        for(int& num : nums){
            mp[num]++;
        }

        int maxFreq = INT_MIN;
        int dominant = 0;
        for(auto& it: mp){
            if(it.second > maxFreq){
                maxFreq = it.second;
                dominant = it.first;
            }
        }

        int count =0;
        for(int& num : nums){
            if(num == dominant){
                count++;
            }
            prefixSum.push_back(count);
        }

        for(int i=0; i<n; i++){
            if(prefixSum[i] > (i+1)/2 && (prefixSum[n-1] - prefixSum[i]) > (n-i-1)/2){
                return i;
            }
        }
        return -1;
    }
};