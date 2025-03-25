class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        vector<vector<int>>result;
        result.push_back(intervals[0]);

        for(int i=1; i<n; i++){
            if(intervals[i][0] < result.back()[1]){
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
            else{
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>>hor;
        vector<vector<int>>ver;

        for(auto& rectangle : rectangles){
            int x1 = rectangle[0];
            int y1 = rectangle[1];
            int x2 = rectangle[2];
            int y2 = rectangle[3];
            hor.push_back({x1, x2});
            ver.push_back({y1, y2});
        }

        vector<vector<int>>result1;
        vector<vector<int>>result2;

        result1 = merge(hor);
        result2 = merge(ver);

        return result1.size() >=3 || result2.size() >= 3;
    }
};