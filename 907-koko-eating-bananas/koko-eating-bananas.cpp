class Solution {
public:
    bool canEatBanana(vector<int>& piles, int h, int mid){
        long long time = 0;
        for(int& banana : piles){
            time += banana % mid == 0 ? 0: 1;
            time += banana/mid;
        }
        if(time <= h) return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int result = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(canEatBanana(piles, h, mid)){
                result = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return result;
    }
};