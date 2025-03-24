class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int start = 0;
        int end = 0;

        int daysOff = 0;

        for(auto& meeting : meetings){
            start = meeting[0];
            if(start > end){
                daysOff += start - end - 1;
            }
            end = max(end, meeting[1]);
        }

        if(end < days){
            daysOff += days - end;
        }
        return daysOff;
    }
};