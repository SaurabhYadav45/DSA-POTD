class Solution {
public:
    // #define ll long long;
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size()/3;
        priority_queue<long long>maxHeap;
        priority_queue<long long, vector<long long>, greater<long long>>minHeap;
        vector<long long>prefix(nums.size(), -1);
        vector<long long>suffix(nums.size(), -1);
        long long sum =0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            maxHeap.push(nums[i]);

            if(maxHeap.size() > n){
                sum -= maxHeap.top();
                maxHeap.pop();
            }

            if(maxHeap.size() == n){
                prefix[i] = sum;
            }
        }
        sum = 0;
        for(int i=nums.size()-1; i>=0; i--){
            sum += nums[i];
            minHeap.push(nums[i]);

            if(minHeap.size() > n){
                sum -= minHeap.top();
                minHeap.pop();
            }

            if(minHeap.size() == n){
                suffix[i] = sum;
            }
        }
        long long ans = LONG_LONG_MAX;
        for(int i=n-1; i<2*n;i++){
            ans  = min(ans, prefix[i] - suffix[i+1]);
        }
        return ans;
    }
};