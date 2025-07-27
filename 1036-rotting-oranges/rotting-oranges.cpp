class Solution {
public:
    vector<vector<int>> directions{{0,1}, {0,-1}, {1,0}, {-1,0}};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        auto isSafe = [&](int x, int y){
            if(x < 0 || x >= m || y < 0 || y >= n){
                return false;
            }
            return true;
        };

        queue<pair<int, int>>q;
        int freshOrange = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                if(grid[i][j] == 1){
                    freshOrange++;
                }
            }
        }

        if(freshOrange == 0) return 0;

        int time = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                
                for(auto& dir: directions){
                    int x = i + dir[0];
                    int y = j + dir[1];
                    if(isSafe(x, y) && grid[x][y] == 1){
                        q.push({x, y});
                        grid[x][y] = 2;
                        freshOrange--;
                    }
                }
            }
            time++;
        }
        
        return (freshOrange == 0) ? time-1 : -1;
    }
};