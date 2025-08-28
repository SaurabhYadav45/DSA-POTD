class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> result(n, vector<int>(n, 0));
        map<int, vector<int>>mp;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int key = i-j;
                mp[key].push_back(grid[i][j]);
            }
        }

        for(auto& it: mp){
            if(it.first >= 0){
                sort(it.second.begin(), it.second.end());
            }
            else{
                sort(it.second.rbegin(), it.second.rend());
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int key = i-j;
                result[i][j] = mp[key].back();
                mp[key].pop_back();
            }
        }
        return result;
    }
};