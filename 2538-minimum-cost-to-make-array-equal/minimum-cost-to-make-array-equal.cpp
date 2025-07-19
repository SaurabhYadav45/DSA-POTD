class Solution {
public:
    long long findCost(vector<int>& nums, vector<int>& cost, long long mid){
        long long calCost = 0;
        for(int i=0; i<nums.size(); i++){
            calCost += abs(nums[i] - mid)*cost[i];
        }
        return calCost;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long result = INT_MAX;
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        while(low <= high){
            long long mid = low + (high-low)/2;
            long long cost1 = findCost(nums, cost, mid);
            long long cost2 = findCost(nums, cost, mid+1);

            result = min(cost1, cost2);
            if(cost2 > cost1){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return result;
    }
};