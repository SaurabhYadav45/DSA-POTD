class Solution {
public:
    vector<vector<int>>directions{{0,1}, {0,-1}, {1,0}, {-1,0}};
    typedef pair<int, pair<int,int>> P;
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        vector<vector<int>>result(n, vector<int>(m, INT_MAX));
        priority_queue<P, vector<P>, greater<P>>pq;

        result[0][0] = 0;
        pq.push({0, {0,0}});

        while(!pq.empty()){
            int currTime = pq.top().first;
            auto cell = pq.top().second;
            int x = cell.first;
            int y = cell.second;
            pq.pop();

            if(x == n-1 && y == m-1){
                return currTime;
            }

            for(auto& dir : directions){
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if(x_ >= 0 && x_ < n && y_ >= 0 && y_ < m){
                    int move = (x_ + y_)%2 == 0 ? 2 : 1;
                    int waitTime = max(moveTime[x_][y_] - currTime , 0);
                    int totalTime = waitTime + currTime + move;

                    if(result[x_][y_] > totalTime){
                        result[x_][y_] = totalTime;
                        pq.push({totalTime, {x_,y_}});
                    }
                }
            }
        }
        return result[n-1][m-1];
    }
};