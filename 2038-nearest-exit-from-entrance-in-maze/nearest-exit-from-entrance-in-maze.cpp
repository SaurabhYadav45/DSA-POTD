class Solution {
public:
    vector<vector<int>>directions{{0,1}, {0,-1}, {1,0}, {-1, 0}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();

        queue<pair<int, int>>q;
        q.push({entrance[0], entrance[1]});

        int step = 0;

        while(!q.empty()){
            int size = q.size();
            while(size--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                if( i == 0 || i == m-1 || j == 0 || j == n-1){
                    if(i != entrance[0] || j != entrance[1]){
                        return step;
                    }
                }

                for(auto& dir: directions){
                    int x = i + dir[0];
                    int y = j + dir[1];
                    if(x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == '.'){
                        q.push({x, y});
                        maze[x][y] = '+';
                    }
                }
            }
            step++;
        }
        return -1;
    }
};