class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int>freeTime;
        freeTime.push_back(startTime[0] - 0);
        for(int i=1; i<n; i++){
            int t = startTime[i] - endTime[i-1];
            freeTime.push_back(t);
        }
        freeTime.push_back(eventTime - endTime[n-1]);

        int result = INT_MIN;
        int sum = 0;
        int i=0, j=0;
        while(j < freeTime.size()){
            sum += freeTime[j];
            if(i < freeTime.size() && j-i+1 > k+1){
                sum -= freeTime[i];
                i++;
            }
             result = max(result, sum);
            j++;
        }
        return result;
    }
};