class Solution {
public:
    void dfs(int src, vector<vector<int>>& stones, vector<bool>&visited){
        visited[src] = true;

        for(int i=0; i<stones.size(); i++){
            int row = stones[src][0];
            int col = stones[src][1];
            if(!visited[i] && (stones[i][0] == row || stones[i][1] == stones[src][1])){
                dfs(i, stones, visited);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool>visited(n, false);
        int count = 0;

        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(i, stones, visited);
                count++;
            }
        }
        return n - count;
    }
};