class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int m = landStartTime.size();
        int n = waterStartTime.size();

        int result = INT_MAX;
        int landRideMinimum = INT_MAX;
        int waterRideMinimum = INT_MAX;

        // find the minimum time taken Land Ride
        for(int i=0; i<m; i++){
            int time  = landStartTime[i] + landDuration[i];
            landRideMinimum = min(landRideMinimum, time);
        }

        // find the minimum time taken Water Ride
        for(int i=0; i<n; i++){
            int time  = waterStartTime[i] + waterDuration[i];
            waterRideMinimum = min(waterRideMinimum, time);
        }

        // Case1: Calculate Minimum time taken  (LAND -> WATER) Ride
        for(int j=0; j<n; j++){
            // Wait for Water ride to start (take the maximum time )
            int landEnd = max(landRideMinimum, waterStartTime[j]); 
            int waterDur = waterDuration[j];
            result = min(result, landEnd + waterDur);
        }

        // Case2: Calculate Minimum time taken  (WATER -> LAND) Ride
        for(int j=0; j<m; j++){
            // Wait for Land ride to start
            int waterEnd = max(waterRideMinimum, landStartTime[j]);
            int landDur = landDuration[j];
            result = min(result, waterEnd + landDur);
        }
        return result;
    }
};