class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());
        int count = 0;
        int day = events[0][0];
        priority_queue<int, vector<int>, greater<int>>pq;
    
        int i = 0;
        while(!pq.empty() || i < n){
            if(pq.empty()){
                day = events[i][0];
            }
            while(i < n && events[i][0] == day){
                pq.push(events[i][1]);
                i++;
            }

            if(!pq.empty()){
                count++;
                pq.pop();
            }

            day++;

            while(!pq.empty() && pq.top() < day){
                pq.pop();
            }
        }
        return count;
    }
};