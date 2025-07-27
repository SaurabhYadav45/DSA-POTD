class Solution {
public:
    vector<vector<int>>directions{{0,1}, {0,-1}, {1, 0}, {-1, 0}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        auto isSafe = [&](int x, int y){
            if(x < 0 || x >= m || y < 0 || y >= n){
                return false;
            }
            return true;
        };

        queue<pair<int, int>>q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0){
                    q.push({i, j});
                }
                else{
                    mat[i][j] = -1;
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
                    if(isSafe(x, y) && mat[x][y] == -1){
                        q.push({x, y});
                        mat[x][y] = mat[i][j]+1;
                    }
                }
            }
        }
        return mat;
    }
};