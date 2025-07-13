class Solution {
public:
    bool isPossible(vector<int>& weights, int days, int capacity){
        int sum = 0;
        int dayCount = 1;
        for(int&weight: weights){
            if(sum + weight <= capacity){
                sum += weight;
            }
            else{
                sum = weight;
                dayCount++;
            }
        }
        return dayCount <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int result = 0;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(isPossible(weights, days, mid)){
                result = mid;
                high = mid-1;
            }
            else{
                low  = mid+1;
            }
        }
        return result;
    }
};