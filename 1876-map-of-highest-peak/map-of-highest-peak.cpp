class Solution {
public:
    vector<vector<int>>directions{{0,1}, {0,-1}, {1, 0}, {-1, 0}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        auto isSafe = [&](int x, int y){
            if(x < 0 || x >= m || y < 0 || y >= n){
                return false;
            }
            return true;
        };

        vector<vector<int>>height(m, vector<int>(n, -1));
        queue<pair<int, int>>q;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(isWater[i][j] == 1){
                    q.push({i, j});
                    height[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            int size = q.size();
            while(size--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(auto& dir : directions){
                    int x = i + dir[0];
                    int y = j + dir[1];
                    if(isSafe(x, y) && height[x][y] == -1){
                        q.push({x, y});
                        height[x][y] = height[i][j]+1;
                    }
                }
            }
        }
        return height;
    }
};