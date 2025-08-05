class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int m = landStartTime.size();
        int n = waterStartTime.size();

        int result = INT_MAX;
        int landStartMinimum = INT_MAX;
        int waterStartMinimum = INT_MAX;

        for(int i=0; i<m; i++){
            int time  = landStartTime[i] + landDuration[i];
            landStartMinimum = min(landStartMinimum, time);
        }

        for(int i=0; i<n; i++){
            int time  = waterStartTime[i] + waterDuration[i];
            waterStartMinimum = min(waterStartMinimum, time);
        }

        for(int j=0; j<n; j++){
            int landEnd = max(landStartMinimum, waterStartTime[j]);
            int waterDur = waterDuration[j];
            result = min(result, landEnd + waterDur);
        }

        for(int j=0; j<m; j++){
            int waterEnd = max(waterStartMinimum, landStartTime[j]);
            int landDur = landDuration[j];
            result = min(result, waterEnd + landDur);
        }

        return result;
    }
};