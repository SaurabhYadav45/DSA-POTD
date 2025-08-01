class Solution {
public:
    bool dfs(int source, int destination, unordered_map<int, vector<int>>&adj, vector<bool>&visited){
        if(source == destination) return true;

        visited[source] = true;

        for(auto& nbr: adj[source]){
            if(!visited[nbr]){
                if(dfs(nbr, destination, adj, visited)){
                    return true;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>>adj;
        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>visited(n, false);

        if(dfs(source, destination, adj, visited)){
            return true;
        }

        return false;
    }
};