class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int m = landStartTime.size();
        int n = waterStartTime.size();

        int result = INT_MAX;

        for(int i=0; i<m; i++){
            int landStart = landStartTime[i];
            int landDur = landDuration[i];
            for(int j=0; j<n; j++){
                int waterStart = waterStartTime[j];
                int waterDur = waterDuration[j];

                // Case 1: LAND -> WATER
                int landEnd = landStart + landDur;
                landEnd = max(landEnd, waterStart); // Wait until the water start
                int finish1 = landEnd + waterDur;

                // Case 2: WATER -> LAND
                int waterEnd = waterStart + waterDur;
                waterEnd = max(waterEnd, landStart); // Wait until the land start
                int finish2 = waterEnd + landDur;

                // Take the minimum of two case and previous result
                result = min({result, finish1, finish2});
            }
        }
        return result;
    }
};



// class Solution {
// public:
//     int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
//         int m = landStartTime.size();
//         int n = waterStartTime.size();

//         int result = INT_MAX;

//         for(int i=0; i<m; i++){
//             int time = landStartTime[i] + landDuration[i];
//             for(int j=0; j<n; j++){
//                 if(waterStartTime[j] <= time){
//                     time += waterDuration[j];
//                 }
//                 else{
//                     time += (waterStartTime[j]-time) + waterDuration[j];
//                 }
//                 result = min(result, time);
//                 time = landStartTime[i] + landDuration[i];
//             }
//         }

//         for(int i=0; i<n; i++){
//             int time = waterStartTime[i] + waterDuration[i];
//             for(int j=0; j<m; j++){
//                 if(landStartTime[j] <= time){
//                     time += landDuration[j];
//                 }
//                 else{
//                     time += (landStartTime[j]-time) + landDuration[j];
//                 }
//                 result = min(result, time);
//                 time = waterStartTime[i] + waterDuration[i];
//             }
//         }
//         return result;
//     }
// };