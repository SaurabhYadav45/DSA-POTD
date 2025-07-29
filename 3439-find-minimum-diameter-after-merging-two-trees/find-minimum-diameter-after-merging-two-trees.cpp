class Solution {
public:
    pair<int, int>bfs(unordered_map<int, vector<int>>&adj, int src){
        queue<int>q;
        unordered_map<int, bool>visited;
        q.push(src);
        visited[src] = true;

        int diameter = 0;
        int farthestNode = src;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int node = q.front();
                q.pop();

                farthestNode = node;

                for(auto& nbr: adj[node]){
                    if(!visited[nbr]){
                        q.push(nbr);
                        visited[nbr] = true;
                    }
                }
            }
            if(!q.empty()){
                diameter++;
            }
        }
        return {farthestNode, diameter};
    }
    int findDiameter(unordered_map<int, vector<int>>&adj){
        auto[farthestNode, distance] = bfs(adj, 0);
        auto[otherEndNode, diameter] = bfs(adj, farthestNode);
        return diameter;
    }
    unordered_map<int, vector<int>> buildADJ(vector<vector<int>>& edges){
        unordered_map<int, vector<int>>adj;
        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int, vector<int>>adj1 = buildADJ(edges1);
        unordered_map<int, vector<int>>adj2 = buildADJ(edges2);

        int diameter1 = findDiameter(adj1);
        int diameter2 = findDiameter(adj2);

        int combined = (diameter1+1)/2 + (diameter2+1)/2 + 1;
        return max({diameter1, diameter2, combined});
    }
};