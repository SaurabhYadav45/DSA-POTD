class Solution {
public:
    bool canComplete(vector<int>& time, int totalTrips, long long mid){
        long long tripCount = 0;
        for(int i=0; i<time.size(); i++){
            tripCount += mid/time[i];
        }
        if(tripCount >= totalTrips) return true;
        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low = 1;
        long long high = *max_element(time.begin(), time.end()) * (long long)totalTrips;
        long long result = 0;
        while(low <= high){
            long long mid = low + (high-low)/2;
            if(canComplete(time, totalTrips, mid)){
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