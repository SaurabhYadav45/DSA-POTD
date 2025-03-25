class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        vector<vector<int>>result;
        result.push_back(intervals[0]);

        for(int i=1; i<n; i++){
            if(intervals[i][0] <= result.back()[1]){
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
            else{
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};



// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         int n = intervals.size();
//         sort(intervals.begin(), intervals.end());

//         int start = intervals[0][0];
//         int end = intervals[0][1];

//         vector<vector<int>>result;

//         for(int i=1; i<n; i++){
//             if(intervals[i][0] > end){
//                 result.push_back({start, end});
//                 start = intervals[i][0];
//                 end = intervals[i][1];
//             }
//             else if(intervals[i][0] <= end){
//                 start = min(start, intervals[i][0]);
//                 end  = max(end, intervals[i][1]);
//             }
//         }
//         result.push_back({start, end});
//         return result;
//     }
// };