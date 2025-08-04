class Solution {
public:
    int dfs(int u, int parent, unordered_map<int, vector<int>>&adj, vector<bool>& hasApple){
        int time = 0;
        for(auto& v: adj[u]){
            if(v == parent) continue;
            int time_from_child = dfs(v, u, adj, hasApple);

            if(time_from_child > 0 || hasApple[v]){
                time += time_from_child + 2;
            }
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int, vector<int>>adj;
        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int result = dfs(0, -1, adj, hasApple);

        return result;
    }
};